using System.ComponentModel.DataAnnotations;

namespace Lab_9.Models;

public class Student
{
    [Key]
    public int Id { get; set; }

    public string Name { get; set; }

    public string Email { get; set; }

    public int Sem {get; set;}
}