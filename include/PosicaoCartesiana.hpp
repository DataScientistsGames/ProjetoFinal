#ifndef POSCARTESIANA_H
#define POSCARTESIANA_H

class PosicaoCartesiana
{
private:
    int _x, _y;

public:

    PosicaoCartesiana(int x, int y);
    PosicaoCartesiana();
    ~PosicaoCartesiana();

    /**
     * @brief Retorna a posição X.
     */
    int getX();

    /**
     * @brief Retorna a posição Y.
     */
    int getY();


    /**
     * @brief Define a posição X como o argumento recebido.
     * @param x O novo valor de X.
     */
    void setX(int);

    /**
     * @brief Define a posição Y como o argumento recebido.
     * @param y O novo valor de Y.
     */
    void setY(int);
};

#endif