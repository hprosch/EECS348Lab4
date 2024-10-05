/*Hannah Prosch 
EECS 148 Lab4
October 4, 2024*/

#include <stdio.h>

float celsius_to_fahrenheit (float celsius) {
      return ((9*celsius)/5) + 32;  
}
float celsius_to_kelvin (float celsius) {
        return celsius + 273.15;
}
float fahrenheit_to_celsius (float fahrenheit) {
        return (5*(fahrenheit - 32))/9;
}
float fahrenheit_to_kelvin (float fahrenheit) {
        return (5*(fahrenheit - 32)/9) + 273.15;
}
float kelvin_to_celsius (float kelvin) {
        return kelvin - 273.15;
}
float kelvin_to_fahrenheit (float kelvin) {
        return ((kelvin - 273.15)*1.8) + 32;
}

void categorize_temperature (float celsius) {
        /*Prints temperature category and weather advisory based
        on temperature in celsius*/
        if (celsius < 0) {
                printf("Temperature category: Freezing.\nWeather advisory: Dress in layers.");
        } else if (celsius < 10) {
                printf("Temperature category: Cold.\nWeather advisory: Wear long sleeves.");
        } else if (celsius < 25) {
                printf("Temperature category: Comfortable.\nWeather advisory: Enjoy the weather.");
        } else if (celsius < 35) {
                printf("Temperature category: Hot.\nWeather advisory: Stay in the shade.");
        } else {
                printf("Temperature category: Extreme heat.\nWeather advisory: Stay indoors.");
        }   
}

int main() {
        float scale, conversion, tempValue, celsius;
        float complete = 0;

        while (complete == 0) {
                /*Get the temperature value from the user*/
                printf("\nEnter the temperature: ");
                scanf("%f", &tempValue);

                /*Get the current scale from the user */
                printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
                scanf("%f", &scale);

                /*Checking for valid scale value. */
                if (scale != 1 && scale != 2 && scale != 3) {
                        printf("\nInvalid scale - please enter a value of 1, 2, or 3.");
                        continue;
                }

                /*Checking to ensure that the value for Kelvin is 
                not a negative value */
                if (tempValue < 0 && scale == 3) {
                        printf("\nPlease enter a non-negative value for Kelvin.");
                        continue;
                }

                /*Get desired scale to convert temperature to */
                printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
                scanf("%f", &conversion);

                /*Checking for valid conversion value.*/
                if (conversion != 1 && conversion != 2 && conversion != 3) {
                        printf("\nInvalid conversion - please enter a value of 1, 2, or 3.");
                        continue;
                }

                /*Handle invalid conversion combination choices */
                if (scale == 1 && conversion == 1) {
                        printf("Cannot convert from celsius to celsius.");
                        continue;
                } else if (scale == 2 && conversion == 2) {
                        printf("Cannot convert from fahrenheit to fahrenheit.");
                        continue;
                } else if (scale == 3 && conversion == 3) {
                        printf("Cannot convert from kelvin to kelvin.");
                        continue;
                }
                /*Ends program once we print conversion, category, and advisory for the user*/
                break;
        }

        /*When input scale is celsius*/
        if (scale == 1) {
                celsius = tempValue;
                if (conversion == 2) {
                        /*Convert from celsius to fahrenheit*/
                        float fahrenheit = celsius_to_fahrenheit(tempValue);
                        printf("\nConverted temperature: %.2f°F\n", fahrenheit);
                } else {
                        /*Convert from celsius to kelvin*/
                        float kelvin = celsius_to_kelvin(tempValue);
                        printf("\nConverted temperature: %.2fK\n", kelvin);
                }
        } else if (scale == 2) {
                /*When input scale is fahrenheit */
                if (conversion == 1) {
                        /*Convert from fahrenheit to celsius*/
                        celsius = fahrenheit_to_celsius(tempValue);
                        printf("\nConverted temperature: %.2f°C\n", celsius);
                } else {
                        celsius = fahrenheit_to_celsius(tempValue);
                        /*Convert from fahrenheit to kelvin*/
                        float kelvin = fahrenheit_to_kelvin(tempValue);
                        printf("\nConverted temperature: %.2fK\n", kelvin);
                }
        } else {
                /*When input scale is kelvin*/
                if (conversion == 1) {
                        /*Convert from kelvin to celsius*/
                        celsius = kelvin_to_celsius(tempValue);
                        printf("\nConverted temperature: %.2f°C\n", celsius);
                } else {
                        celsius = kelvin_to_celsius(tempValue);
                        /*Convert from kelvin to fahrenheit*/
                        float fahrenheit = kelvin_to_fahrenheit(tempValue);
                        printf("\nConverted temperature: %.2f°F\n", fahrenheit);
                }
        }
        /*Categorizes the temperature in categories with weather advisories.*/
        categorize_temperature(celsius); 
}

