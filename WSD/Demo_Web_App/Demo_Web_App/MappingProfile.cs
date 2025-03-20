using AutoMapper;
using Demo_Web_App.Models;

namespace Demo_Web_App;

public class MappingProfile : Profile
{
    public MappingProfile()
    {
        CreateMap<Product, ProdDTO>();
    }

}