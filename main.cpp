#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <future>
#include <fstream>
#include <string>

using namespace std;

//wymiary
const float height=800.f;
const float width=1200.f;
const float ch_width=800.f;
const float ch_height=600.f;
const float radius_m=0.5f;
const float max_velocity=90000.f;
const int number_of_balls=1000;
const float delta_s=0.02f;
const float delta_time=0.005;
const int limit=60000;
//stala do dzielenia na kwadraty
const int divv=5;
const int strips=4;

//ball box
const float left_x=50;
const float right_x=100;
const float up_y=50;
const float down_y=100;
//okno
const float left_border=50;
const float right_border=250;
const float up_border=50;
const float down_border=250;
const int zero_=0;

struct point{
    float x;
    float y;
    float v_x;
    float v_y;
};

point balls[limit]={};
sf::CircleShape particles[limit];
const int stan_size=12;
int stan[stan_size][stan_size][stan_size][stan_size]={};
//do entropii
const float range_x=(right_border-left_border)/10;
const float range_y=(down_border-up_border)/10;
const float m_real_velocity=float(max_velocity/number_of_balls*2);
pair<float,float> zz=make_pair(100,100);
//okno z wykresem
sf::Vertex line_x[2]{
    sf::Vertex(sf::Vector2f(zz.first,ch_height-zz.first)),
    sf::Vertex(sf::Vector2f(ch_width-zz.first,ch_height-zz.first))
};
sf::Vertex line_y[2]{
    sf::Vertex(sf::Vector2f(zz.first,zz.first)),
    sf::Vertex(sf::Vector2f(zz.first,ch_height-zz.first))
};


const float scale_x=15;
const float scale_y=200;

float random_float(const float &d,const float &u) {
	return ((float)rand() / RAND_MAX) * (u-d) + d;
}
//do obliczania entropii
float calculate_ent(){
        float score=number_of_balls*log(number_of_balls)-number_of_balls,f;
        for(int i=0;i<stan_size-2;i++){
            for(int j=0;j<stan_size-2;j++){
                for(int k=0;k<stan_size-2;k++){
                    for(int h=0;h<stan_size-2;h++){
                            f=stan[i][j][k][h];
                            if(f!=0)
                        score+=(-f*log(f)+f);
                    }
                }
            }
        }
        return score;
}
//do sortowania po wspolrzednych
bool compare_coor_y(point a,point b){
    return (a.y<=b.y);
}
bool compare_coor_x(point a, point b){
    return (a.x<=b.x);
}
//funkcja pomocnicza
bool helper(int &indeks,int &k){
    float diff_x,diff_y;
    for(int i=indeks-1;i>=indeks-k;i--){
        diff_x=balls[i].x-balls[indeks].x;
        diff_y=balls[i].y-balls[indeks].y;
        if(sqrt(diff_x*diff_x+diff_y*diff_y)<2*radius_m+delta_s)return 0;
    }
    return 1;
}
//funkcja inicjalizujaca ustawienie kulek
void init(sf::RenderWindow &window){
    float divv_f=divv;
    float one_square=ceil(number_of_balls/(divv_f*divv_f));
    float up=max_velocity/(2*number_of_balls);
    float down=-max_velocity/(2*number_of_balls);
    float range_x=right_x-left_x,range_y=down_y-up_y;
    range_x/=divv;range_y/=divv;
    int indeks=0,box_counter=0;
    for(int i=0;i<divv;i++){
        for(int j=0;j<divv;j++){
                box_counter++;
            for(int k=0;k<one_square;k++){
                balls[indeks].v_x=random_float(down,up);
                balls[indeks].v_y=random_float(down,up);
                balls[indeks].x=random_float(left_x+i*range_x+radius_m+delta_s,left_x+(i+1)*range_x-radius_m-delta_s);
                balls[indeks].y=random_float(up_y+j*range_y+radius_m+delta_s,up_y+(j+1)*range_y-radius_m-delta_s);
                while(helper(indeks,k)==0){
                    balls[indeks].x=random_float(left_x+i*range_x+radius_m+delta_s,left_x+(i+1)*range_x-radius_m-delta_s);
                    balls[indeks].y=random_float(up_y+j*range_y+radius_m+delta_s,up_y+(j+1)*range_y-radius_m-delta_s);
                }
                particles[indeks].setRadius(radius_m);
                particles[indeks].setPosition(sf::Vector2f(balls[indeks].x,balls[indeks].y));
                particles[indeks].setOrigin(radius_m,radius_m);
                //particles[indeks].setOutlineThickness(delta_s/2);
                //particles[indeks].setOutlineColor(sf::Color::Magenta);
                particles[indeks].setFillColor(sf::Color::Cyan);
                indeks++;
            }
        }
        if(box_counter==number_of_balls%(divv*divv)){
            one_square=ceil(number_of_balls/(divv*divv));
        }
    }
}
//pudelko
void box(sf::RenderWindow &window){
    sf::Vertex vertices[5]=
    {
        sf::Vertex(sf::Vector2f(left_border,up_border)),
        sf::Vertex(sf::Vector2f(left_border,down_border)),
        sf::Vertex(sf::Vector2f(right_border,down_border)),
        sf::Vertex(sf::Vector2f(right_border,up_border)),
        sf::Vertex(sf::Vector2f(left_border,up_border))
    };
    window.draw(vertices,5,sf::LineStrip);
}
void ball_box(sf::RenderWindow &window){
    sf::Vertex vertices[5]{
        sf::Vertex(sf::Vector2f(right_x,up_y)),
        sf::Vertex(sf::Vector2f(left_x,up_y)),
        sf::Vertex(sf::Vector2f(left_x,down_y)),
        sf::Vertex(sf::Vector2f(right_x,down_y)),
        sf::Vertex(sf::Vector2f(right_x,up_y))
    };
    window.draw(vertices,5,sf::LineStrip);
}
//odbicia od scianek
void check_borders(){
    sort(balls,balls+number_of_balls,compare_coor_x);
    //float line=balls[0].x;

    int i=0;
    while(i<number_of_balls&&abs(-left_border+(balls[i].x+2*radius_m))<=delta_s||balls[i].x<left_border){
        if(balls[i].v_x>0){i++;continue;}
        balls[i].v_x=-balls[i].v_x;
        i++;
    }
    i=number_of_balls-1;
    //cout<<"right border: "<<right_border-(balls[i].x+radius_m)<<endl;
    while(i>=0&&abs(right_border-(balls[i].x))<=delta_s+radius_m||balls[i].x>right_border){
        if(balls[i].v_x<0){i--;continue;}
        balls[i].v_x=-balls[i].v_x;
        i--;
    }
    sort(balls,balls+number_of_balls,compare_coor_y);
    i=0;
    //cout<<"up border: "<<-up_border+(balls[i].y-radius_m)<<endl;
    while(i<number_of_balls&&-up_border+(balls[i].y-radius_m)<=delta_s||balls[i].y<up_border){
        if(balls[i].v_y>0){i++;continue;}
        balls[i].v_y=-balls[i].v_y;
        i++;
    }
    i=number_of_balls-1;
    //cout<<"down border: "<<down_border-(balls[i].y+radius_m)<<endl;
    while(i>=0&&abs(down_border-(balls[i].y))<=delta_s+radius_m||balls[i].y>down_border){
        if(balls[i].v_y<0){i--;continue;}
        balls[i].v_y=-balls[i].v_y;
        i--;
    }
}
//rysuje kulki
bool sketch(sf::RenderWindow &window,sf::View &view,const int left,const int right){
    float l=view.getCenter().x-view.getSize().x/2-8*radius_m;
    float r=view.getCenter().x+view.getSize().x/2+8*radius_m;
    float d=view.getCenter().y+view.getSize().x/2+8*radius_m;
    float u=view.getCenter().y-view.getSize().y/2-8*radius_m;
    int x,y,vx,vy;
    for(int i=left;i<right;i++){
        if(particles[i].getPosition().x<=r&&particles[i].getPosition().x>=l&&particles[i].getPosition().y>=u&&particles[i].getPosition().y<=d)
        window.draw(particles[i]);
        x=floor((balls[i].x-left_border)/range_x);
        y=floor((balls[i].y-up_border)/range_y);
        vx=floor((balls[i].v_x+m_real_velocity)/10);
        vy=floor((balls[i].v_y+m_real_velocity)/10);
        //cout<<"tak"<<endl;
        stan[abs(x)][abs(y)][abs(vx)][abs(vy)]++;
        //cout<<"nie"<<endl;
    }
    return true;
}
void crash(point &a,point &b){
    //najpierw dla punktu a
    pair<float,float> new_velocity_a_perp,new_velocity_a_parr;
    float alpha,line_x=a.x-b.x,line_y=a.y-b.y;
    if(line_x*a.v_x+line_y*a.v_y<0){
        line_x=-line_x;
        line_y=-line_y;
    }
    alpha=(a.v_x+line_y/line_x*a.v_y)/(line_x+line_y*line_y/line_x);
    new_velocity_a_parr=make_pair(a.v_x-alpha*line_x,a.v_y-alpha*line_y);
    new_velocity_a_perp=make_pair(alpha*line_x,alpha*line_y);
    //dla punktu b
    pair<float,float> new_velocity_b_parr,new_velocity_b_perp;
    if(line_x*b.v_x+line_y*b.v_y<0){
        line_x=-line_x;
        line_y=-line_y;
    }
    alpha=(b.v_x+line_y/line_x*b.v_y)/(line_x+line_y*line_y/line_x);
    new_velocity_b_parr=make_pair(b.v_x-alpha*line_x,b.v_y-alpha*line_y);
    new_velocity_b_perp=make_pair(alpha*line_x,alpha*line_y);
    a.v_x=new_velocity_a_parr.first+new_velocity_b_perp.first;
    a.v_y=new_velocity_a_parr.second+new_velocity_b_perp.second;
    b.v_x=new_velocity_b_parr.first+new_velocity_a_perp.first;
    b.v_y=new_velocity_b_parr.second+new_velocity_a_perp.second;
}
bool checking_crashes(const int &left_i,const int &right_i){
    sf::Time tim;
    sf::Clock clock;
    sort(balls+left_i,balls+right_i,compare_coor_x);
    for(int i=left_i;i<right_i;i++)
    {
        int indeks=i+1;
        while(indeks<number_of_balls&&-balls[i].x+balls[indeks].x<=2*radius_m+delta_s){
            //sprawdzamy odleglosc
            float diff_x=balls[i].x-balls[indeks].x,diff_y=balls[i].y-balls[indeks].y;
            //eliminacja koloizji
            if(-balls[i].v_x*diff_x-balls[i].v_y*diff_y<0&&balls[indeks].v_x*diff_x+balls[indeks].v_y*diff_y<0){
                indeks++;
                continue;
            }
            if(sqrt(diff_x*diff_x+diff_y*diff_y)<=2*radius_m+delta_s){
                crash(balls[i],balls[indeks]);
            }indeks++;
        }
    }
    return true;
}
void checking_crashes_parallel(){
    sort(balls,balls+number_of_balls,compare_coor_y);
    vector<int> strip_lines;
    for(int i=0;i<=strips;i++){
        strip_lines.push_back(number_of_balls*(i/strips));
    }
    future<bool> result1=std::async(std::launch::async,checking_crashes,ref(strip_lines[0]),ref(strip_lines[1]));
    future<bool> result2=std::async(std::launch::async,checking_crashes,ref(strip_lines[1]),ref(strip_lines[2]));
    future<bool> result3=std::async(std::launch::async,checking_crashes,ref(strip_lines[2]),ref(strip_lines[3]));
    checking_crashes(strip_lines[3],strip_lines[4]);
    result1.get();
    result2.get();
    result3.get();
}
void move_balls(const float &seconds){
    float new_x,new_y;
    for(int i=0;i<number_of_balls;i++){
            new_x=balls[i].x+balls[i].v_x*seconds;
            new_y=balls[i].y+balls[i].v_y*seconds;
        particles[i].setPosition(sf::Vector2f(new_x,new_y));
        balls[i].x=new_x;
        balls[i].y=new_y;
    }
}
int main()
{
    fstream wy;
    wy.open("entropia.txt",ios::out);
    sf::RenderWindow window(sf::VideoMode(width,height), "Entropia");
    sf::RenderWindow chart(sf::VideoMode(ch_width,ch_height),"Wykres entropii");
    sf::View view(sf::FloatRect(0,0,width,height));
    sf::View view_chart(sf::FloatRect(0,0,ch_width,ch_height));
    view.setCenter(sf::Vector2f(left_border/2+right_border/2,up_border/2+down_border/2));
    sf::Clock clock;
    sf::Time tim;
    vector<sf::Vertex> curve;
    curve.push_back(sf::Vertex(sf::Vector2f(zz.first,ch_height-zz.second)));
    float d=delta_time,set_min;
    sf::Text seconds;
    sf::Text entropia;
    sf::Font font;
    if(!font.loadFromFile("OpenSans-Regular.ttf")){
        cout<<"error"<<endl;
    }
        entropia.setCharacterSize(20);
        entropia.setFont(font);

        seconds.setCharacterSize(20);
        seconds.setFont(font);
    //inicjalicacja
    srand(time(0));
    init(window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed){
                window.close();
                //chart.close();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                view.zoom(1.1);
                window.setView(view);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                view.zoom(0.9);
                window.setView(view);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                view.move(sf::Vector2f(0,-10));
                window.setView(view);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                view.move(sf::Vector2f(0,10));
                window.setView(view);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                view.move(sf::Vector2f(10,0));
                window.setView(view);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                view.move(sf::Vector2f(-10,0));
                window.setView(view);
            }
        }

        //nietykalne
        window.clear();
        chart.clear();
        sketch(window,view,zero_,number_of_balls);
        float c=calculate_ent();
        if(d==delta_time)set_min=c;
        //cala zabawa
        check_borders();
        checking_crashes(zero_,number_of_balls);
        //checking_crashes_parallel();
                    tim=clock.getElapsedTime();
                    //cout<<"checking_crashes "<<tim.asSeconds()<<endl;
        move_balls(delta_time);
        box(window);
        ball_box(window);
        chart.draw(line_x,2,sf::Lines);
        chart.draw(line_y,2,sf::Lines);
        string s=to_string(int(c));
        string ss=to_string(d);
        entropia.setString(s);
        sf::Vector2f ent1(15,(zz.second-c+set_min)/scale_y+400);
        sf::Vector2f sec(zz.first+d*scale_x,ch_height-80);
        sf::Vector2f p(zz.first+d*scale_x,(zz.second-c+set_min)/scale_y+400);
        entropia.setPosition(ent1);
        seconds.setPosition(sec);
        seconds.setString(ss);
        sf::Vertex l[3]={sf::Vertex(ent1),sf::Vertex(p),sf::Vertex(sec)};
        chart.draw(l,2,sf::Lines);
        chart.draw(&l[1],2,sf::Lines);
        chart.draw(seconds);
        chart.draw(entropia);
        d+=delta_time;

        curve.push_back(p);
        chart.draw(&curve[0],curve.size(),sf::LineStrip);
                    wy<<c<<endl;
                //czysci tablice
                {
                    for(int i=0;i<stan_size;i++){
                        for(int j=0;j<stan_size;j++){
                            for(int k=0;k<stan_size;k++){
                                for(int h=0;h<stan_size;h++){
                                    stan[i][j][k][h]=0;
                                }
                            }
                        }
                    }
                }
        window.display();
        chart.display();
        window.setFramerateLimit(60);
    }
    return 0;
}
