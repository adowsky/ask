void start_engine(); // włącza silnik
void stop_engine(); // wyłącza silnik
void turn_on_led(char nr); // zapala diodę LED (0 - czerwona; 1 - żólta; 2 - zielona)
void turn_off_led(char nr); // gasi diodę
void write_LCD(const char* text); // wypisuje na wyświetlaczu text (max 20 znaków)

char last_reed_switch;
int half_circles;
void init()// wykonuje się na początku programu
{
    half_circles = 0;
    last_reed_switch = 0;
}
void key_pressed(char key) // wykonuje się do wciśnięciu klawisza (lewy górny róg to 0, prawy górny róg to 3 itd. do prawego dolnego rogu 15)
{

}
void reed_switch(char nr) // wykonuje się, gdy kontaktron wyczuje magnes (nr to numer kontaktronu: 0 lub 1)
{
    if(last_reed_switch != nr)
    {
        last_reed_switch = nr;
        half_circles++;
    }
}
void tick() // wykonuje się co 1ms
{

}
