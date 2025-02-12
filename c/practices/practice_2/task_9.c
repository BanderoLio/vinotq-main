#include <stdio.h>
#include <stdlib.h>

enum State
{
    Sunny,
    Cloudy,
    Rainy
};

struct Weather
{
    float temperature;
    float wetness;
    enum State state;
};

int main()
{
    int n;
    printf("Hi!\nPlease enter amount of weather entries: ");
    scanf("%d", &n);

    struct Weather weather;

    printf("\nPlease temperature (float), wetness (float) and state (Sunny, Cloudy or Rainy): ");
    scanf("%f %f %s", &weather.temperature, &weather.wetness, weather.state);
    printf("Temperature: %.1f C, Wetness: %.1f%, Condition: ", weather.temperature, weather.wetness);

    // https://learn.microsoft.com/ru-ru/cpp/c-language/switch-statement-c?view=msvc-170

    switch (weather.state)
    {
    case Sunny:
        printf("Sunny\n");
        break;
    case Cloudy:
        printf("Cloudy\n");
        break;
    case Rainy:
        printf("Rainy\n");
        break;
    }
}