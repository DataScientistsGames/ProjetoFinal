#ifndef POSCARTESIANA_H
#define POSCARTESIANA_H

class PosicaoCartesiana
{
private:
    double _x, _y;

public:

    PosicaoCartesiana(double x, double y);
    PosicaoCartesiana(const PosicaoCartesiana& pos);
     /**
     * @brief Cria posição em 0x e 0y.
     */
    PosicaoCartesiana();
    ~PosicaoCartesiana();

    /**
     * @brief Retorna a posição X.
     */
    double getX();

    /**
     * @brief Retorna a posição Y.
     */
    double getY();


    /**
     * @brief Define a posição X como o argumento recebido.
     * @param x O novo valor de X.
     */
    void setX(double);

    /**
     * @brief Define a posição Y como o argumento recebido.
     * @param y O novo valor de Y.
     */
    void setY(double);
};

#endif