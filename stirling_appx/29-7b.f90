program error2
implicit none
real(kind = 16)::a,b
integer::h, i
open(10, file='data.gnu')
do h = -4510,0,10
b = 1.2
a= 10**(real(h)/100)
write(10,*) (a), (cos(b) - (sin(b + a) - sin(b))/a)
enddo
end program 
