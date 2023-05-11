#include <metal_stdlib>
using namespace metal;
kernel void rsqracc(device const float* in, device float* out, device int &n, device int &__FPC_block0, uint mtl_thread [[thread_position_in_grid]])
{
int __FPC_blockidx0 = mtl_thread / __FPC_block0;
float my_x;
float my_y;
float my_z;
my_x = in[((int)mtl_thread * 3)];
my_y = in[(((int)mtl_thread * 3) + 1)];
my_z = in[(((int)mtl_thread * 3) + 2)];
float other_x;
float other_y;
float other_z;
float dx;
float dy;
float dz;
float r2;
float acc = 0.0f;
for (int i = 0; (i < n); i++)
{
if ((i != (int)mtl_thread))
{
other_x = in[(i * 3)];
other_y = in[((i * 3) + 1)];
other_z = in[((i * 3) + 2)];
dx = (other_x - my_x);
dy = (other_y - my_y);
dz = (other_z - my_z);
r2 = (((dx * dx) + (dy * dy)) + (dz * dz));
acc = (acc + (1.0f / r2));
}
}
out[(int)mtl_thread] = acc;

}
