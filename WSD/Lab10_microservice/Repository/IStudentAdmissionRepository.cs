using StudentAdmission.Models;

namespace StudentAdmission.Repository
{
    public interface IStudentAdmissionRepository
    {
        IEnumerable<Student> GetStudents();

        Student GetStudent(int id);

        void InsertStudent(Student student);

        void UpdateStudent(Student student);
        void DeleteStudent(int id);

        void Save();

    }
}
