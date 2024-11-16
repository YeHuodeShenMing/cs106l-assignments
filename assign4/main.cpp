/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  // 得到的是iterator， 解引用
  auto min_temp = *std::min_element(dailyWeather.begin(), dailyWeather.end());
  auto max_temp = *std::max_element(dailyWeather.begin(), dailyWeather.end());
  auto sum_temp = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0);
  double avg_temp = sum_temp / (double)dailyWeather.size();

  Forecast forecast = {min_temp, max_temp, avg_temp};

  return forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
  std::vector<Forecast> forecast_vecs;
  // 使用 back_inserter 给空vector插入新元素
  std::transform(weatherData.begin(), weatherData.end(), std::back_inserter(forecast_vecs),
                 compute_forecast);

  return forecast_vecs;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  std::vector<Forecast> result = forecastData;
  // 全局变量不用捕获
  auto temp_filter = [](Forecast fcst) {
    return (fcst.max_temp - fcst.min_temp) < kMaxTempRequirement ||
           fcst.avg_temp < uAvgTempRequirement;
  };
  result.erase(std::remove_if(result.begin(), result.end(), temp_filter), result.end());
    for (auto v : result) {
        if (v.avg_temp < 60)
    {std::cout << v.min_temp <<" "<< v.max_temp << " " << v.avg_temp << "\n";}
  }
  return result;
}

std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::random_device rd;
  std::mt19937 g(rd());

  std::vector<Forecast> result = forecastData;

  std::shuffle(result.begin(), result.end(), g);

  return result;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  auto Data = weatherData;
  auto result = get_forecasts(Data);
  result = get_filtered_data(result);
  result = get_shuffled_data(result);

  return result;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"