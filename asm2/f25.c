//! -O0 -fomit-frame-pointer
// Let's figure out the calling conventions on this compiler!

long f(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) {
    return arg1 + 2*arg2 + 3*arg3 + 4*arg4 + 5*arg5 + 6*arg6;
}
