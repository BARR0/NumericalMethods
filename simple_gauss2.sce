//A = [2,3,7;2,4,3;1,1,1];
//B = [12, 9, 3];

//A = [2,6,0;1,7,4;3,4,1]
//B = [3,25,-1]

//A = [5,2,-1,3;3,-9,3,-13;4,0,4,-3;2,3,4,-6]
//B = [23;12;-5;5]

A = [1,1,1,1;1,1,0,0;0,0,0,1;-1,1,-3,5]
B = [-2,10,3,-1]

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
R(rX)=B(rX)/A(rX,rX);
for i=rX-1:-1:1
    tmp=0;
    for j=i+1:rX
        tmp=tmp+A(i,j)*R(j);
    end
    R(i)=(B(i)-tmp)/A(i,i);
end

disp(R)
