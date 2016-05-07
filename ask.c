void start_engine(); // włącza silnik
void stop_engine(); // wyłącza silnik
void turn_on_led(char nr); // zapala diodę LED (0 - czerwona; 1 - żólta; 2 - zielona)
void turn_off_led(char nr); // gasi diodę
void write_LCD(const char* text); // wypisuje na wyświetlaczu text (max 20 znaków)

char last_reed_switch; //ostatni wyczuty kontaktron
int half_circles; //liczba przebytych połówek kółek przez chomika
int circles;
int engine_count; //zmienna na potrzebę odliczania czasu pracy silnika
int circles_initiating_engine = 5; //po ilu przebytych kółkach włącza się silnik
int engine_working_time = 5; //na ile sekund włącza się silnik
void init()// wykonuje się na początku programu
{
    circles_initiating_engine = 5;
    engine_working_time = 5;
    engine_count = 0;
    half_circles = 0;
    circles = 0;
    last_reed_switch = '0';
    stop_engine();
    write_LCD("Hello!");
}
void key_pressed(char key) // wykonuje się do wciśnięciu klawisza (lewy górny róg to 0, prawy górny róg to 3 itd. do prawego dolnego rogu 15)
{
    switch(key)
    {
        case '0':
        {

        }break;
        case '1':
        {

        }break;
        case '2':
        {

        }break;
        case '3':
        {
            //write_LCD("Circles:");
        }break;
        case '4':
        {

        }break;
        case '5':
        {

        }break;
        case '6':
        {

        }break;
        case '7':
        {

        }break;
        case '8':
        {

        }break;
        case '9':
        {

        }break;
        case '10':
        {

        }break;
        case '11':
        {

        }break;
        case '12':
        {

        }break;
        case '13':
        {

        }break;
        case '14':
        {

        }break;
        case '15':
        {

        }break;
    }
}
void reed_switch(char nr) // wykonuje się, gdy kontaktron wyczuje magnes (nr to numer kontaktronu: 0 lub 1)
{
    if(last_reed_switch != nr)
    {
        last_reed_switch = nr;
        half_circles++;
        if(half_circles%2==0)
        {
            circles++;
        }
    }
}
void tick() // wykonuje się co 1ms
{
    if(half_circles==circles_initiating_engine*2)
    {
        engine_count+=1000*engine_working_time;
        half_circles = 0;
    }
    if(engine_count<=0) stop_engine();
    else
    {
        start_engine();
        engine_count--;
    }
}
