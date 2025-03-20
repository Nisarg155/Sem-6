using System.Transactions;
using Microsoft.AspNetCore.Mvc;
using StudentAdmission.Models;
using StudentAdmission.Repository;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace StudentAdmission.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class StudentAdmissionController : ControllerBase
    {
        private readonly IStudentAdmissionRepository _studentAdmissionRepository;

        public StudentAdmissionController(IStudentAdmissionRepository studentAdmissionRepository)
        {
            _studentAdmissionRepository = studentAdmissionRepository;
        }



        // GET: api/<StudentAdmissionController>
        [HttpGet]
        public IActionResult Get()
        {
            var studnets = _studentAdmissionRepository.GetStudents();
            return new OkObjectResult(studnets);
        }

        // GET api/<StudentAdmissionController>/5
        [HttpGet("{id}")]
        public IActionResult Get(int id)
        {
           var studnet = _studentAdmissionRepository.GetStudent(id);
            return new OkObjectResult(studnet);
        }

        // POST api/<StudentAdmissionController>
        [HttpPost]
        public IActionResult Post([FromBody] Student student)
        {
            using(var scope = new TransactionScope())
            {
                _studentAdmissionRepository.InsertStudent(student);
                scope.Complete();
                return CreatedAtAction(nameof(Student),new {id = student.StuentId}, student);
            }

            
            
        }

        // PUT api/<StudentAdmissionController>/5
        [HttpPut("{id}")]
        public IActionResult Put(int id, [FromBody] Student student)
        {
            if(student != null)
            {
                using(var scope = new TransactionScope())
                {
                    _studentAdmissionRepository.UpdateStudent(student);
                    scope.Complete();
                    return new OkResult();
                }
            }
            return new NoContentResult();

        }

        // DELETE api/<StudentAdmissionController>/5
        [HttpDelete("{id}")]
        public IActionResult Delete(int id)
        {
            _studentAdmissionRepository.DeleteStudent(id);
            return new OkResult();
        }
    }
}
