#ifndef _MACHREG_H
#define _MACHREG_H
/*
 * machreg.h
 *	Register definitions for i386
 */
#include <sys/types.h>
#include <sys/param.h>

/*
 * This is what is added to a user's stack when an event is
 * delivered.
 */
struct evframe {
	ulong ev_prevsp;
	ulong ev_previp;
	char ev_event[EVLEN];
};

/*
 * This is the shape of the kernel stack after taking an interrupt
 * or exception.  For machine traps which don't provide an error
 * code, we push a 0 ourselves.  "traptype" is from sys/trap.h.
 * edi..eax are in pushal format.
 */
struct trapframe {
	ulong esds;
	ulong edi, esi, ebp, espdummy, ebx, edx, ecx, eax;
	ulong traptype;
	ulong errcode;
	ulong eip, ecs;
	ulong eflags;
	ulong esp, ess;
};

/*
 * Tell if given descriptor is from user mode
 */
#define USERMODE(tf) (((tf)->ecs & 0x3) == 3)

/*
 * Bits in eflags
 */
#define	F_CF	0x00000001	/* carry */
#define	F_PF	0x00000004	/* parity */
#define	F_AF	0x00000010	/* BCD stuff */
#define	F_ZF	0x00000040	/* zero */
#define	F_SF	0x00000080	/* sign */
#define	F_TF	0x00000100	/* single step */
#define	F_IF	0x00000200	/* interrupts */
#define	F_DF	0x00000400	/* direction */
#define	F_OF	0x00000800	/* overflow */
#define	F_IOPL	0x00003000	/* IO privilege level */
#define	F_NT	0x00004000	/* nested task */
#define	F_RF	0x00010000	/* resume flag */
#define	F_VM	0x00020000	/* virtual 8086 */

/*
 * Bits in errcode when handling page fault
 */
#define EC_KERNEL 4	/* Fault from kernel mode */
#define EC_WRITE 2	/* Access was a write */
#define EC_PROT 1	/* Page valid, but access modes wrong */

#endif /* _MACHREG_H */
