n = int(input())
st = []
a = list(map(int, input().split()))
for x in a:
    while st:
        if st[-1] == x:
            st.pop()
            x *= 2
        elif st[-1] < x :
            st.pop()
        else:
            break
    st.append(x)
print(max(st))