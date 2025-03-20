using Microsoft.EntityFrameworkCore;

namespace Lab_10_2.Modals;

public class StudentAttandenceContext : DbContext
{
    public StudentAttandenceContext(DbContextOptions options) : base(options)
    {
    }
    public DbSet<Student> Students { get; set; }
}