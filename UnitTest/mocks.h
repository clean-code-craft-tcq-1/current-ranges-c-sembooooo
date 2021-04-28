#pragma once

extern int PrintfInputParam[3];
extern int call_printf;

extern int stub_printf(const char *format , ...);
extern void Reset_mocks(void);