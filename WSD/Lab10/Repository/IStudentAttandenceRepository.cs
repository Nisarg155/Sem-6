namespace Lab10.Repository;
using Lab10.Models;

public interface IStudentAttandenceRepository
{
    IEnumerable<Student> GetStudents();

    Student GetStudent(int id);

    void InsertStudent(Student student);

    void UpdateStudent(Student student);
    void DeleteStudent(int id);

    void Save();


}