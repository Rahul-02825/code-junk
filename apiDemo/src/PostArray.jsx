import { useMutation } from "@tanstack/react-query";
import { useState } from "react";
import axios from "axios";

const fetchWeather = async (city) => {
  const response = await axios.get(
    `http://api.weatherapi.com/v1/current.json?key=a2b2937d86794e44946163638250503&q=${city}&aqi=no`
  );
  return response.data;
};

const GetData = () => {
  const [city, setCity] = useState("");
  const [weatherHistory, setWeatherHistory] = useState([]); // Store all responses

  const mutation = useMutation({
    mutationFn: fetchWeather,
    onSuccess: (data) => {
      setWeatherHistory((prevHistory) => [...prevHistory, data]); // Add to history
    },
  });

  const handleSubmit = (e) => {
    e.preventDefault();
    if (city.trim()) {
      mutation.mutate(city); // Fetch weather for entered city
    }
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          value={city}
          onChange={(e) => setCity(e.target.value)}
          placeholder="Enter city name"
        />
        <button type="submit">Get Weather</button>
      </form>

      {mutation.isLoading && <p>Loading...</p>}
      {mutation.error && <p>Error: {mutation.error.message}</p>}

      <h2>Weather History</h2>
      {weatherHistory.length === 0 ? (
        <p>No data yet</p>
      ) : (
        <ul>
          {weatherHistory.map((weather, index) => (
            <li key={index}>
              <strong>{weather.location.name}:</strong> {weather.current.condition.text}, {weather.current.temp_c}°C
            </li>
          ))}
        </ul>
      )}
    </div>
  );
};

export default GetData;
