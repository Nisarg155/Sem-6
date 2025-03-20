using Lab_9.Models;
using Microsoft.EntityFrameworkCore;

namespace Lab_9;

public class Program
{
    public static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        // Using In memory Database
        // builder.Services.AddDbContext<StudentContext>(opt => opt.UseInMemoryDatabase("StudentDB"));

        // Fetching Connection String
        var connectionString = builder.Configuration.GetConnectionString("ConnectionString");
        // Using Database
        builder.Services.AddDbContext<StudentContext>(options =>
            options.UseMySql(
                connectionString,
                new MySqlServerVersion(new Version(10, 11, 10)) // Adjust to your MariaDB version
            )
        );


        // Add services to the container.

        builder.Services.AddControllers();
        // Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
        builder.Services.AddEndpointsApiExplorer();
        builder.Services.AddSwaggerGen();

        var app = builder.Build();

        // Configure the HTTP request pipeline.
        if (app.Environment.IsDevelopment())
        {
            app.UseSwagger();
            app.UseSwaggerUI();
        }

        app.UseHttpsRedirection();

        app.UseAuthorization();


        app.MapControllers();

        app.Run();
    }
}