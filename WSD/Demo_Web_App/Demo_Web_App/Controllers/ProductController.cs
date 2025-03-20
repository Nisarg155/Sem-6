using AutoMapper;
using Demo_Web_App.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Demo_Web_App.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProductController : ControllerBase
    {
        private readonly IMapper _mapper;
        private static List<Product> _products = new List<Product>
        {
            new Product { Id = 1, Name = "Apple", Price = 10, Category = "Fruit" },
            new Product { Id = 2, Name = "Banana", Price = 20, Category = "Fruit" },
            new Product { Id = 3, Name = "Orange", Price = 30, Category = "Fruit" },
            new Product { Id = 4, Name = "Pineapple", Price = 50, Category = "Fruit" },
        };

        [HttpGet]
        public ActionResult<IEnumerable<Product>> GetProducts()
        {
            return Ok(_products);
        }


        [HttpGet("{id:int}")]
        public ActionResult<Product> GetProduct(int id)
        {
            var product = _products.FirstOrDefault(p => p.Id == id);

            if (product == null) return NotFound();
            return Ok(product);
        }

        [HttpPost]
        public ActionResult<Product> PostProduct(Product product)
        {
            _products.Add(product);
            return CreatedAtAction(nameof(GetProduct),new {id = product.Id}, product);
        }

        [HttpPut("{id:int}")]
        public IActionResult PutProduct([FromRoute] int id,[FromBody] Product product)
        {
            if (id != product.Id) return BadRequest();

            var toUpdate = _products.FirstOrDefault(p => p.Id == id);
            if (toUpdate == null) return NotFound();
            toUpdate.Name = product.Name;
            toUpdate.Price = product.Price;
            toUpdate.Category = product.Category;
            return NoContent();
        }

        [HttpGet("headers")]
        public IActionResult GetProductHeaders([FromHeader(Name="ID")] int id)
        {
            return Ok(id);
        }

        // [HttpPost("upload")]
        // public IActionResult Upload([FromForm] IFormFile? file)
        // {
        //     if(file == null || file.Length == 0) return BadRequest();
        //
        //     return Ok("File Received");
        // }

        [HttpDelete("{id}")]
        public IActionResult DeleteProduct(int id)
        {
            var product = _products.FirstOrDefault(p => p.Id == id);
            if (product == null) return NotFound();

            _products.Remove(product);
            return NoContent();
        }

        [HttpGet("mapper/{id:int}")]
        public IActionResult GetMapper(int id)
        {
            var product = _products.FirstOrDefault(p => p.Id == id);
            if (product == null) return NotFound();

            var Productmapper = _mapper.Map<ProdDTO>(product);
            return Ok(Productmapper);
        }



    }
}
