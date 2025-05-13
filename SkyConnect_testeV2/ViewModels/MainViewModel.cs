using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using SkyConnect_2Version.Models;
using SkyConnect_2Version.Controllers;

namespace SkyConnect_2Version.ViewModels
{
    public class MainViewModel : IWeatherViewModel
    {
        private readonly IAppController _controller;

        public string City { get; set; } = "Lisboa";
        public List<DailyForecast> Forecasts { get; private set; } = new();
        public bool HasError { get; private set; } = false;

        public event Action StateChanged;

        public MainViewModel(IAppController controller)
        {
            _controller = controller;
            _controller.OnUserAuthenticated += user =>
                Console.WriteLine($"Bem-vindo {user.Username}!");
        }

        public bool Login(string username, string password)
        {
            return _controller.Login(username, password);
        }

        public async Task FetchWeather()
        {
            var forecast = await _controller.GetWeather(City);
            if (forecast == null)
            {
                HasError = true;
                Forecasts.Clear();
            }
            else
            {
                HasError = false;
                Forecasts = forecast.Forecasts;
            }

            NotifyStateChanged();
        }

        private void NotifyStateChanged() => StateChanged?.Invoke();
    }
}