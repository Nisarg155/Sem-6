namespace Lab10.Repository;
using Lab10.Models;

public class StudentAttandenceRepository : IStudentAttandenceRepository
{
    private readonly StudentAdttendanceContext _context;
    public StudentAttandenceRepository(StudentAdttendanceContext context) {
        _context = context;
    }

    public void DeleteStudent(int id)
    {
        var student = _context.Students.Find(id);
        _context.Students.Remove(student);
        Save();
    }

    public Student GetStudent(int id)
    {
        return _context.Students.Find(id);
    }

    public IEnumerable<Student> GetStudents()
    {
        return _context.Students.ToList();
    }

    public void InsertStudent(Student student)
    {
        _context.Add(student);
        Save();
    }

    public void Save()
    {
        _context.SaveChanges();

    }

    public void UpdateStudent(Student student)
    {
        _context.Entry(student).State = Microsoft.EntityFrameworkCore.EntityState.Modified;
        Save();

    }

}