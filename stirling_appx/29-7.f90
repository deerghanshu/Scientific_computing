program error1
implicit none
real::pi, n, e, s, fact
integer:: i, j
pi = acos(-1.0)
do j = 1,10
   n = j
   s = (2*pi*n)**0.5*(n/exp(1.0))**n
   fact = 1
   do i = 1,j
    fact = fact*i
   enddo
   Print *, n, s, fact, fact - s, (fact-s)/fact
enddo
end program