namespace Lab_10_2.Modals;
using System.ComponentModel.DataAnnotations;

public class Student
{
    [Key]
    public int StudentId { get; set; }
    public int Semester { get; set; }
    public double AttendancePercetage { get; set; }
}