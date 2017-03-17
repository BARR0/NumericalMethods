//A = [2,3,7;2,4,3;1,1,1];
//B = [12, 9, 3];

//A = [2,6,0;1,7,4;3,4,1]
//B = [3,25,-1]

//A = [5,2,-1,3;3,-9,3,-13;4,0,4,-3;2,3,4,-6]
//B = [23;12;-5;5]

A = [1,1,1,1;-1,1,-3,5;1,1,0,0;0,0,0,1]
B = [0;0;0;0]

rX=size(A,1);



for k=1:rX-1
    for i=k+1:rX
        tmp=A(i,k)/A(k,k);
        for j=k:rX
            A(i,j)=A(i,j)-tmp*A(k,j);
        end
        B(i)=B(i)-tmp*B(k);
    end
end

R = []
for i = rX: -1:2
    for j = i-1: -1: 1
        tmp = A(j,i)/A(i,i);
        A(j,:) = A(j,:)-tmp*A(i,:);
        B(j)=B(j)-tmp*B(i);
        B(i)=B(i)/A(i,i);
        A(i,i)=A(i,i)/A(i,i);
        R(i)=B(i);
    end
end
R(1) = B(1)/A(1, 1)

disp(R)
