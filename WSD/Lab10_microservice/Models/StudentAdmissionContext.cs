using Microsoft.EntityFrameworkCore;

namespace StudentAdmission.Models
{
    public class StudentAdmissionContext : DbContext
    {
        public StudentAdmissionContext(DbContextOptions<StudentAdmissionContext> options) : base(options)
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
                    Name = "nisarg",
                    AdmissionDate = new DateTime(2025, 2, 20),
                    AdmissionBranch = "Computer Engineering"
                }
                ,
                new Student
                {
                    StuentId = 2,
                    Name = "neha",
                    AdmissionDate = new DateTime(2025, 2, 20),
                    AdmissionBranch = "Computer Engineering"
                }
            );
        }
    }
}