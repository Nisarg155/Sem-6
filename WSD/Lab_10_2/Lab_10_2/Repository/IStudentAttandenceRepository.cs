using Lab_10_2.Modals;

namespace Lab_10_2.Repository;

public interface IStudentAttandenceRepository
{
    IEnumerable<Student> GetStudents();
    Student GetStudent(int id);
    void AddStudent(Student student);
    void DeleteStudent(int id);
    void UpdateStudent(Student student);
    void Save();
}