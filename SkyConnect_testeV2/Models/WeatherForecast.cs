using System.Collections.Generic;

namespace SkyConnect_2Version.Models
{
    public class DailyForecast
    {
        public string Date { get; set; }
        public string MinTemp { get; set; }
        public string MaxTemp { get; set; }
        public string Description { get; set; }
    }

    public class WeatherForecast
    {
        public string City { get; set; }
        public List<DailyForecast> Forecasts { get; set; }
    }
}