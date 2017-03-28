A = [2,3,7;2,4,3;1,1,1]
B = [2;7;3]
x = []
[rA cA] = size(A)

for i = 1:1:rA
    tmp = A;
    tmp(:,i) = B;
    x(i) = det(tmp)/det(A);
end

disp (x);
