namespace Lab10.Models;
using System.ComponentModel.DataAnnotations;


public class Student
{
    [Key]
    public int StuentId { get; set; }
    public int Semester { get; set; }
    public double Attendance_Percentage { get; set; }
}