#include <vector>

class Map {
    protected:
        std::vector <std::vector<char>> map;
        int length_, height_;

    public:
        Map(int, int);
        Map();

        // mutators
        void initMap        ();
        void setLength      (int);
        void setHeight      (int);
        void setObject      (int, int, char);

        // accessor
         int getLength      () const;
         int getHeight      () const;
        char getObject      (int, int) const;
    	bool isInsideMap    (int, int) const;
};

Map :: Map(int row, int col) {
    length_ = col;
    height_ = row;
    initMap();
}
Map :: Map() : Map(1, 1) {}

void Map :: initMap() {
    //create dynamic 2D array using std::vector
    map.resize(length_); //create rows

    for (int i=0; i<length_; ++i) {
        map[i].resize(height_); //resize each rows
    }
    // fill map
    for (int i=0; i<length_; i++) {
        for (int j=0; j<height_; j++) {
            map[j][i] = 0;
        }
    }
}

void Map :: setLength(int col) {
    length_ = col;
}

void Map :: setHeight(int row) {
    height_ = row;
}

void Map :: setObject(int row, int col, char item) {
    map[row][col] = item;
}

int Map :: getLength() const {
     return length_; 
}

int Map :: getHeight() const {
    return height_;
}

char Map :: getObject(int row, int col) const {
    return map[row][col];
}

bool Map :: isInsideMap(int row, int col) const {
    return ((col < 0 || col >= length_) || (row < 0 || row >= height_)) ? false : true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

class HiddenMap : public Map {
    private:
        std::vector <std::vector<bool>> fov;
    public:
        HiddenMap(int, int);
        HiddenMap();

        // mutators
        void initMap    ();
        void reveal     (int, int);

        // accessor
        bool isReveal   (int, int) const;
};


HiddenMap :: HiddenMap(int row, int col) {
    length_ = col;
    height_ = row;
    initMap();
}
HiddenMap :: HiddenMap() : HiddenMap(1, 1) {}

void HiddenMap :: initMap() {
    //create dynamic 2D array using std::vector
    map.resize(length_); //create rows
    fov.resize(length_); //create rows

    for (int i=0; i<length_; ++i) {
        map[i].resize(height_); //resize each rows
        fov[i].resize(height_); //resize each rows
    }
    // fill map
    for (int i=0; i<length_; i++) {
        for (int j=0; j<height_; j++) {
            map[j][i] = 0;
            fov[j][i] = 0;
        }
    }
}

void HiddenMap :: reveal(int row, int col) {
    fov[row][col] = 1;
}

bool HiddenMap :: isReveal(int row, int col) const {
    return fov[row][col];
}