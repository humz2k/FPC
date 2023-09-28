#include <metal_stdlib>
using namespace metal;
kernel void add2D(device const float* in, device float &mul, device float* out, device int &__FPC_block0, uint mtl_thread [[thread_position_in_grid]])
{
int __FPC_blockidx0 = mtl_thread / __FPC_block0;
out[((int)mtl_thread * 3)] = (out[((int)mtl_thread * 3)] + (in[((int)mtl_thread * 3)] * mul));
out[(((int)mtl_thread * 3) + 1)] = (out[(((int)mtl_thread * 3) + 1)] + (in[(((int)mtl_thread * 3) + 1)] * mul));
out[(((int)mtl_thread * 3) + 2)] = (out[(((int)mtl_thread * 3) + 2)] + (in[(((int)mtl_thread * 3) + 2)] * mul));

}

kernel void calc_acc(device const float* in, device float* out, device int &n, device int &__FPC_block0, uint mtl_thread [[thread_position_in_grid]])
{
int __FPC_blockidx0 = mtl_thread / __FPC_block0;

float my_x = in[((int)mtl_thread * 3)];
float my_y = in[(((int)mtl_thread * 3) + 1)];
float my_z = in[(((int)mtl_thread * 3) + 2)];


float r2;
float mul;

float acc_x = 0.0f;
float acc_y = 0.0f;
float acc_z = 0.0f;
for (int i = 0; (i < n); i++)
{
if ((i != (int)mtl_thread))
{
float other_x = in[(i * 3)];
float other_y = in[((i * 3) + 1)];
float other_z = in[((i * 3) + 2)];
float dx = (other_x - my_x);
float dy = (other_y - my_y);
float dz = (other_z - my_z);
r2 = (((dx * dx) + (dy * dy)) + (dz * dz));
if ((r2 != 0.0f))
{
mul = sqrt((1.0f / r2));
acc_x = (acc_x + (mul * dx));
acc_y = (acc_y + (mul * dy));
acc_z = (acc_z + (mul * dz));
}
}
}
out[((int)mtl_thread * 3)] = acc_x;
out[(((int)mtl_thread * 3) + 1)] = acc_y;
out[(((int)mtl_thread * 3) + 2)] = acc_z;

}
