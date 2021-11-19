#include <iostream>
#include <vector>
#include <fstream>
#include <string>



enum MoveType{
    Up,
    Down,
    Right,
    Left
};

enum Tile{
    Empty,
    Wall,
    Player
};

class GameManger{
private:
    std::vector<std::vector<Tile>> table;
    int player_coords[2];
    int width,height;

    std::vector<std::string> split(std::string line,char delimeter){
        std::vector<std::string> words;
        std::string text="";
        for(int i = 0; i< line.length();i++){
            if(line[i]==delimeter){
                words.push_back(text);
                text="";
            }
            else{
                text+= line[i];
            }
        }
        return words;


    }
    
    void generate_table(){
        std::ifstream myfile("../map-layouts/map.map");
        std::string line;
        std::getline(myfile,line);
        std::cout<<(line);
        width=std::stoi(line);
        height=std::stoi(line);
        table = std::vector<std::vector<Tile>>();
        table.resize(width);
        for(auto& n : table){
            n=std::vector<Tile>();
            n.resize(height);
        }

        int i = 0;
        std::cout<<std::endl;
        while(std::getline(myfile,line)){
            std::vector<std::string> w = split(line,' ');
            for(int j=0;j < w.size();j++){
                std::cout << w[j];
                table[i][j]=(Tile)std::stoi(w[j]);
            }
            std::cout<<std::endl;
            i++;
        }

        

    }

    void print_table(){
        for(int i = 0; i< width; i++){
            for (int j =0; j< height;j++){
                if(player_coords[0] == j && player_coords[1] == i)std::cout<<"P ";
                else std::cout<<table[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    

    bool check_collison(int x, int y){
        if (x <0 || x >= width || y < 0 || y >=height )return false;


        if(table[x][y] != Empty) return false;
        std::cout<<table[x][y]<<std::endl;
        return true;
    }

public:
    
    GameManger(){
        std::cout<<"Creating GameManger"<<std::endl;
        width=10;
        height=10;
        generate_table();
        
        player_coords[0]=5;
        player_coords[1]=5;
        print_table();
        std::cout<<std::endl;
        for(int i =0 ;i < 5; i++ )move_command(Left);
        print_table();
        std::cout<<"Created GameManger"<<std::endl;
    }
    GameManger(bool is_tests){
        
    }

    void place_player(int x, int y){

    }
    void place_wall(int x, int y){

    }

    void move_command(MoveType move){
        int current_x, current_y;
        current_x=player_coords[1];
        current_y=player_coords[0];
        switch(move){
            case Left:
                current_y--;
            break;
            case Right:
                current_y++;
            break;
            case Up:
                current_x++;
            break;
            case Down:
                current_x--;
            break;
        }
        if(check_collison(current_x,current_y)){
            player_coords[1]=current_x;
            player_coords[0]=current_y;
        }
        
    }

    void tick(){
        
    }

    int get_width(){
        return width;
    }
    int get_height(){
        return height;
    }

    Tile get_table_x_y(int x, int y){
        if(x == player_coords[1] && y == player_coords[0])return Player;
        return table[x][y];
    }

    void new_game(){
        player_coords[0]=1;
        player_coords[1]=2;
    }

    int* get_player_coords(){
        return player_coords;
    }

};