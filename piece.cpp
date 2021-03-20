class Piece {
    protected:
        int coX, coY;
    public:
        Piece(int, int);
        Piece();

        // mutators
        void setCor (int, int);
        void setX   (int);
        void setY   (int);

        // accessor
         int getX() const;
         int getY() const;
};

Piece :: Piece(int x, int y) {
    coX = x;
    coY = y;
}
Piece :: Piece() : Piece(-1, -1) {}

void Piece :: setCor(int x, int y) {
    coX = x;
    coY = y;
}

void Piece :: setX(int x) {
    coX = x;
}

void Piece :: setY(int y) {
    coY = y;
}

int Piece :: getX() const {
    return coX;
}

int Piece :: getY() const {
    return coY;
}

class BoardPiece : public Piece {
    protected:
        int limX, limY;
    public:
        BoardPiece(int, int, int, int);
        BoardPiece();

        // mutators
        void setLim     (int, int);
        void setLimX    (int);
        void setLimY    (int);

        // accessor
         int getLimX    () const;
         int getLimY    () const;
        bool isInterval (int, int) const;
};

BoardPiece::BoardPiece(int x, int y, int limX, int limY) {
    coX = x;
    coY = y;
    this->limX = limX;
    this->limY = limY;
}

BoardPiece :: BoardPiece() : BoardPiece(-1, -1, -1, -1) {}

void BoardPiece :: setLim(int x, int y) {
    limX =  x;
    limY =  y;
}

void BoardPiece :: setLimX(int x) {
    limX = x;
}

void BoardPiece :: setLimY(int y) {
    limY = y;
}

int BoardPiece :: getLimX() const {
    return limX;
}

int BoardPiece :: getLimY() const {
    return limY;
}

bool BoardPiece :: isInterval(int x, int y) const {
    return (x >= 0 && x < limX && y >= 0 && y < limY);
}

class DirectionalPiece : public BoardPiece {
    private:
        int vel, noDir, dir = 0;
    public:
        DirectionalPiece(int, int, int, int, int, int);
        DirectionalPiece();

        // mutators
        void setVel     (int);
        void setNoOfDir (int);
        void setDir     (int);
        //assume dir clockwise
        void turnRight  ();
        void turnLeft   ();

        // accessor
        int getVel      () const;
        int getNoOfDir  () const;
        int getDir      () const;
    
};

DirectionalPiece :: DirectionalPiece (int x, int y, int limX, int limY, int vel, int noDir) {
    coX = x;
    coY = y;
    this->limX  = limX;
    this->limY  = limY;
    this->vel   = vel;
    this->noDir = noDir;
}

DirectionalPiece :: DirectionalPiece() : DirectionalPiece(-1, -1, -1, -1, -1, -1) {}

void DirectionalPiece :: setVel(int v) {
    vel = v;
}

void DirectionalPiece :: setNoOfDir(int n) {
    noDir = n;
}

void DirectionalPiece :: setDir(int d) {
    dir = d;
}

int DirectionalPiece :: getVel() const {
    return vel;
}

int DirectionalPiece :: getNoOfDir() const {
    return noDir;
}

int DirectionalPiece :: getDir() const {
    return dir;
}

void DirectionalPiece::turnRight() {
    dir = (dir + 1) % noDir;
}

void DirectionalPiece::turnLeft() {
    dir = (dir + noDir - 1) % noDir;
}

