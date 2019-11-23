function gpp
{
    # https://codeforces.com/blog/entry/15547
    GPP_ARGS="-Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op \
            -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align                           \
            -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2                          \
            -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -g";
    if [[ $PWD == */codebook/Codechef/* ]]
    then
        command g++ -std=c++14 $GPP_ARGS "$1.cpp" -o "$1.o"
    elif [[ $PWD == */codebook/Codeforces/* ]]
    then
        command g++ -std=c++17 $GPP_ARGS "$1.cpp" -o "$1.o"
    else
        command g++ $@
    fi
}
alias g++=gpp

function create
{
    TEMPLATE=~/codebook/utils/template.cpp
    for arg in $@
    do
        cp $TEMPLATE $PWD/$arg.cpp
    done
}

alias run="~/codebook/utils/run.sh"
alias clean="find . -type f -name '*.o' -exec rm {} +;   \
             find . -type f -name 'input' -exec rm {} +; \
             find . -type f -name 'test' -exec rm {} +"
