using System.Net.Http;
using System.Threading.Tasks;
using Newtonsoft.Json;
using SkyConnect_2Version.Models;
using System.Collections.Generic;

namespace SkyConnect_2Version.Services
{
    public class WeatherService : IWeatherService
    {
        private readonly HttpClient _httpClient;

        public WeatherService(HttpClient httpClient)
        {
            _httpClient = httpClient;
        }

        public async Task<WeatherForecast?> GetWeatherAsync(string city)
        {
            try
            {
                var url = $"https://wttr.in/{city}?format=j1";
                var response = await _httpClient.GetStringAsync(url);
                dynamic data = JsonConvert.DeserializeObject(response);

                var list = new List<DailyForecast>();

                foreach (var day in data.weather)
                {
                    list.Add(new DailyForecast
                    {
                        Date = day.date,
                        MinTemp = day.mintempC + " °C",
                        MaxTemp = day.maxtempC + " °C",
                        Description = day.hourly[4].weatherDesc[0].value
                    });
                }

                return new WeatherForecast
                {
                    City = city,
                    Forecasts = list
                };
            }
            catch
            {
                return null;
            }
        }
    }
}