using Microsoft.EntityFrameworkCore;

namespace Lab10.Models;

public class StudentAdttendanceContext : DbContext
{
    public StudentAdttendanceContext(DbContextOptions options) : base(options)
    {
    }

    public DbSet<Student> Students { get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<Student>().HasData(
            new Student
            {
                StuentId = 1,
                Semester = 6,
                Attendance_Percentage = 86.5
            }
            ,
            new Student
            {
                StuentId = 2,
                Semester = 6,
                Attendance_Percentage = 88.5
            }
        );
    }
}