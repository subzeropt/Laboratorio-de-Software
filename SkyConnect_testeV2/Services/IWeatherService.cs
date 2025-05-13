using System.Threading.Tasks;
using SkyConnect_2Version.Models;

namespace SkyConnect_2Version.Services
{
    public interface IWeatherService
    {
        Task<WeatherForecast?> GetWeatherAsync(string city);
    }
}