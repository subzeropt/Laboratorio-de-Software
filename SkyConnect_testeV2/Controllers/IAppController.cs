using System.Threading.Tasks;
using SkyConnect_2Version.Models;

namespace SkyConnect_2Version.Controllers
{
    public interface IAppController
    {
        bool Login(string username, string password);
        Task<WeatherForecast?> GetWeather(string city);
    }
}