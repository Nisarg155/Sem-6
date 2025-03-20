using System.ComponentModel.DataAnnotations;

namespace StudentAdmission.Models
{
    public class Student
    {
        [Key]
        public int StuentId { get; set; }
        public string Name { get; set; }
        public DateTime AdmissionDate { get; set; }
        public string AdmissionBranch { get; set; }
    }
}

