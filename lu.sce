A = [1, 2; 2, 1]
//X = []
B = [3; 3]

[L, U] = lu(A)

// Generar matriz aumentada y desplegar
AUM = [L B]
X = AUM
[rX cX] = size(X)

// Eliminación hacia adelante
for p=1:1:rX-1      //Fila del pivote
    pivote = X(p,p);
    for i=p+1:1:rX      //Fila a procesar
        prim_fila = X(i,p)
        X(i,:) = X(i,:) - (X(p, :)/pivote)*prim_fila
    end
end

for i = 3:rX
    for j = 3:rX + 1
        AUM(i, j) = AUM(i, j) - AUM(2, j)*AUM(i, 2)/AUM(2, 2)
    end
    AUM(i, 2) = 0
end
