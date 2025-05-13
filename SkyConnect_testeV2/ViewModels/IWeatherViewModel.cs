using System.Collections.Generic;
using System.Threading.Tasks;
using SkyConnect_2Version.Models;

namespace SkyConnect_2Version.ViewModels
{
    public interface IWeatherViewModel
    {
        string City { get; set; }
        List<DailyForecast> Forecasts { get; }
        bool HasError { get; }
        bool Login(string username, string password);
        Task FetchWeather();
    }
}