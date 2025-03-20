using System.ComponentModel.DataAnnotations;

namespace Demo_Web_App.Models;

public class Product
{
    [Required]
    public int Id { get; set; }
    [Required]
    [StringLength(50,MinimumLength = 2)]
    public string Name { get; set; }
    [Required]
    [Range(0.1,double.MaxValue,ErrorMessage=" Price must be between 0.1 and double.MaxValue  ")]
    public decimal Price { get; set; }
    public string Category { get; set; }
}