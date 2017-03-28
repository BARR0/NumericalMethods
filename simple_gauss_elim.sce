// Declara la matriz cuadrada de coeficientes como A
// Declara el vector columna de constantes como B

//A = [2,6,0;1,7,4;3,4,1]
//B = [3;25;-1]

A = [5,2,-1,3;3,-9,3,-13;4,0,4,-3;2,3,4,-6]
B = [23;12;-5;5]

//A = [1,1,1,1;1,1,0,0;0,0,0,1;-1,1,-3,5]
//B = [-2;10;3;-1]

//A = [1,1,1,1;-1,1,-3,5;1,1,0,0;0,0,0,1]
//B = [0;0;0;0]

//A = [1,2;4,6]
//B = [0;0]

// Generar matriz aumentada y desplegar
AUM = [A B]
X = AUM
[rX cX] = size(X)

// Eliminación hacia adelante
for p=1:1:rX-1      //Fila del pivote
    pivote = X(p,p);
    for i=p+1:1:rX      //Fila a procesar
        prim_fila = X(i,p);
        X(i,:) = X(i,:) - (X(p, :)/pivote)*prim_fila;
    end
    disp(X)
end

// Forward substitution

R = []
R(rX) = X(rX, cX)/X(rX, cX - 1);
for i=rX-1:-1:1
    tmp=0;
    for j=i+1:1:cX - 1
        tmp=tmp+X(i,j)*R(j);
    end
    R(i)=(X(i, cX)-tmp)/X(i,i);
end

disp(R)
