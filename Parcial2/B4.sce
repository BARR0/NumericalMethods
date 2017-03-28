// Codigo sin usar rref()
//A = [2,-6,-1;-3,-1,7;-8,1,-2]
//B = [-38;-34;-20]

//rX=size(A,1);
//for k=1:rX-1
//    for i=k+1:rX
//       tmp=A(i,k)/A(k,k);
//        for j=k:rX
//            A(i,j)=A(i,j)-tmp*A(k,j);
//        end
//        B(i)=B(i)-tmp*B(k);
//    end
//end
//R = []
//for i = rX: -1:2
//    for j = i-1: -1: 1
//        tmp = A(j,i)/A(i,i);
//        A(j,:) = A(j,:)-tmp*A(i,:);
//        B(j)=B(j)-tmp*B(i);
//        B(i)=B(i)/A(i,i);
//        A(i,i)=A(i,i)/A(i,i);
//        R(i)=B(i);
//    end
//end
//R(1) = B(1)/A(1, 1)
//disp(R)

A = [2,-6,-1;-3,-1,7;-8,1,-2];
B = [-38;-34;-20];
AUM = [A B];
disp(rref(AUM))
