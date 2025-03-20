using Lab_10_2.Modals;

namespace Lab_10_2.Repository;

public class StudentAttandenceRepository : IStudentAttandenceRepository
{
    private readonly StudentAttandenceContext _context;
    public StudentAttandenceRepository(StudentAttandenceContext context)
    {
        _context = context;
    }

    public IEnumerable<Student> GetStudents()
    {
        return _context.Students.ToList();
    }

    public Student GetStudent(int id)
    {
        return _context.Students.Find(id);
    }

    public void AddStudent(Student student)
    {
        _context.Students.Add(student);
        Save();
    }

    public void DeleteStudent(int id)
    {
        var student = _context.Students.Find(id);
        _context.Students.Remove(student);
        Save();
    }

    public void UpdateStudent(Student student)
    {
        _context.Entry(student).State = Microsoft.EntityFrameworkCore.EntityState.Modified;
        Save();
    }

    public void Save()
    {
        _context.SaveChanges();
    }
}