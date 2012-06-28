/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD: projects/armv6/sys/compat/svr4/svr4_sysent.c 228136 2011-11-29 15:24:19Z cognet $
 * created from FreeBSD: head/sys/compat/svr4/syscalls.master 227691 2011-11-19 06:35:15Z ed 
 */

#include <sys/types.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <netinet/in.h>
#include <compat/svr4/svr4.h>
#include <compat/svr4/svr4_types.h>
#include <compat/svr4/svr4_signal.h>
#include <compat/svr4/svr4_proto.h>

#define AS(name) (sizeof(struct name) / sizeof(register_t))

/* The casts are bogus but will do for now. */
struct sysent svr4_sysent[] = {
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 0 = unused */
	{ AS(sys_exit_args), (sy_call_t *)sys_sys_exit, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 1 = exit */
	{ 0, (sy_call_t *)sys_fork, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 2 = fork */
	{ AS(read_args), (sy_call_t *)sys_read, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 3 = read */
	{ AS(write_args), (sy_call_t *)sys_write, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 4 = write */
	{ AS(svr4_sys_open_args), (sy_call_t *)svr4_sys_open, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 5 = svr4_sys_open */
	{ AS(close_args), (sy_call_t *)sys_close, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 6 = close */
	{ AS(svr4_sys_wait_args), (sy_call_t *)svr4_sys_wait, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 7 = svr4_sys_wait */
	{ AS(svr4_sys_creat_args), (sy_call_t *)svr4_sys_creat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 8 = svr4_sys_creat */
	{ AS(link_args), (sy_call_t *)sys_link, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 9 = link */
	{ AS(unlink_args), (sy_call_t *)sys_unlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 10 = unlink */
	{ AS(svr4_sys_execv_args), (sy_call_t *)svr4_sys_execv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 11 = svr4_sys_execv */
	{ AS(chdir_args), (sy_call_t *)sys_chdir, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 12 = chdir */
	{ AS(svr4_sys_time_args), (sy_call_t *)svr4_sys_time, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 13 = svr4_sys_time */
	{ AS(svr4_sys_mknod_args), (sy_call_t *)svr4_sys_mknod, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 14 = svr4_sys_mknod */
	{ AS(chmod_args), (sy_call_t *)sys_chmod, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 15 = chmod */
	{ AS(chown_args), (sy_call_t *)sys_chown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 16 = chown */
	{ AS(svr4_sys_break_args), (sy_call_t *)svr4_sys_break, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 17 = svr4_sys_break */
	{ AS(svr4_sys_stat_args), (sy_call_t *)svr4_sys_stat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 18 = svr4_sys_stat */
	{ AS(lseek_args), (sy_call_t *)sys_lseek, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 19 = lseek */
	{ 0, (sy_call_t *)sys_getpid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 20 = getpid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 21 = old_mount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 22 = sysv_umount */
	{ AS(setuid_args), (sy_call_t *)sys_setuid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 23 = setuid */
	{ 0, (sy_call_t *)sys_getuid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 24 = getuid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 25 = stime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 26 = ptrace */
	{ AS(svr4_sys_alarm_args), (sy_call_t *)svr4_sys_alarm, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 27 = svr4_sys_alarm */
	{ AS(svr4_sys_fstat_args), (sy_call_t *)svr4_sys_fstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 28 = svr4_sys_fstat */
	{ 0, (sy_call_t *)svr4_sys_pause, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 29 = svr4_sys_pause */
	{ AS(svr4_sys_utime_args), (sy_call_t *)svr4_sys_utime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 30 = svr4_sys_utime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 31 = stty */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 32 = gtty */
	{ AS(svr4_sys_access_args), (sy_call_t *)svr4_sys_access, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 33 = svr4_sys_access */
	{ AS(svr4_sys_nice_args), (sy_call_t *)svr4_sys_nice, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 34 = svr4_sys_nice */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 35 = statfs */
	{ 0, (sy_call_t *)sys_sync, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 36 = sync */
	{ AS(svr4_sys_kill_args), (sy_call_t *)svr4_sys_kill, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 37 = svr4_sys_kill */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 38 = fstatfs */
	{ AS(svr4_sys_pgrpsys_args), (sy_call_t *)svr4_sys_pgrpsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 39 = svr4_sys_pgrpsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 40 = xenix */
	{ AS(dup_args), (sy_call_t *)sys_dup, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 41 = dup */
	{ 0, (sy_call_t *)sys_pipe, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 42 = pipe */
	{ AS(svr4_sys_times_args), (sy_call_t *)svr4_sys_times, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 43 = svr4_sys_times */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 44 = profil */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 45 = plock */
	{ AS(setgid_args), (sy_call_t *)sys_setgid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 46 = setgid */
	{ 0, (sy_call_t *)sys_getgid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 47 = getgid */
	{ AS(svr4_sys_signal_args), (sy_call_t *)svr4_sys_signal, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 48 = svr4_sys_signal */
	{ AS(svr4_sys_msgsys_args), (sy_call_t *)svr4_sys_msgsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 49 = svr4_sys_msgsys */
	{ AS(svr4_sys_sysarch_args), (sy_call_t *)svr4_sys_sysarch, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 50 = svr4_sys_sysarch */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 51 = acct */
	{ AS(svr4_sys_shmsys_args), (sy_call_t *)svr4_sys_shmsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 52 = svr4_sys_shmsys */
	{ AS(svr4_sys_semsys_args), (sy_call_t *)svr4_sys_semsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 53 = svr4_sys_semsys */
	{ AS(svr4_sys_ioctl_args), (sy_call_t *)svr4_sys_ioctl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 54 = svr4_sys_ioctl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 55 = uadmin */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 56 = exch */
	{ AS(svr4_sys_utssys_args), (sy_call_t *)svr4_sys_utssys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 57 = svr4_sys_utssys */
	{ AS(fsync_args), (sy_call_t *)sys_fsync, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 58 = fsync */
	{ AS(svr4_sys_execve_args), (sy_call_t *)svr4_sys_execve, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 59 = svr4_sys_execve */
	{ AS(umask_args), (sy_call_t *)sys_umask, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 60 = umask */
	{ AS(chroot_args), (sy_call_t *)sys_chroot, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 61 = chroot */
	{ AS(svr4_sys_fcntl_args), (sy_call_t *)svr4_sys_fcntl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 62 = svr4_sys_fcntl */
	{ AS(svr4_sys_ulimit_args), (sy_call_t *)svr4_sys_ulimit, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 63 = svr4_sys_ulimit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 64 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 65 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 66 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 67 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 68 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 69 = reserved */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 70 = advfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 71 = unadvfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 72 = rmount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 73 = rumount */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 74 = rfstart */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 75 = sigret */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 76 = rdebug */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 77 = rfstop */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 78 = rfsys */
	{ AS(rmdir_args), (sy_call_t *)sys_rmdir, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 79 = rmdir */
	{ AS(mkdir_args), (sy_call_t *)sys_mkdir, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 80 = mkdir */
	{ AS(svr4_sys_getdents_args), (sy_call_t *)svr4_sys_getdents, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 81 = svr4_sys_getdents */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 82 = libattach */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 83 = libdetach */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 84 = sysfs */
	{ AS(svr4_sys_getmsg_args), (sy_call_t *)svr4_sys_getmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 85 = svr4_sys_getmsg */
	{ AS(svr4_sys_putmsg_args), (sy_call_t *)svr4_sys_putmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 86 = svr4_sys_putmsg */
	{ AS(svr4_sys_poll_args), (sy_call_t *)svr4_sys_poll, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 87 = svr4_sys_poll */
	{ AS(svr4_sys_lstat_args), (sy_call_t *)svr4_sys_lstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 88 = svr4_sys_lstat */
	{ AS(symlink_args), (sy_call_t *)sys_symlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 89 = symlink */
	{ AS(readlink_args), (sy_call_t *)sys_readlink, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 90 = readlink */
	{ AS(getgroups_args), (sy_call_t *)sys_getgroups, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 91 = getgroups */
	{ AS(setgroups_args), (sy_call_t *)sys_setgroups, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 92 = setgroups */
	{ AS(fchmod_args), (sy_call_t *)sys_fchmod, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 93 = fchmod */
	{ AS(fchown_args), (sy_call_t *)sys_fchown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 94 = fchown */
	{ AS(svr4_sys_sigprocmask_args), (sy_call_t *)svr4_sys_sigprocmask, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 95 = svr4_sys_sigprocmask */
	{ AS(svr4_sys_sigsuspend_args), (sy_call_t *)svr4_sys_sigsuspend, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 96 = svr4_sys_sigsuspend */
	{ AS(svr4_sys_sigaltstack_args), (sy_call_t *)svr4_sys_sigaltstack, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 97 = svr4_sys_sigaltstack */
	{ AS(svr4_sys_sigaction_args), (sy_call_t *)svr4_sys_sigaction, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 98 = svr4_sys_sigaction */
	{ AS(svr4_sys_sigpending_args), (sy_call_t *)svr4_sys_sigpending, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 99 = svr4_sys_sigpending */
	{ AS(svr4_sys_context_args), (sy_call_t *)svr4_sys_context, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 100 = svr4_sys_context */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 101 = evsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 102 = evtrapret */
	{ AS(svr4_sys_statvfs_args), (sy_call_t *)svr4_sys_statvfs, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 103 = svr4_sys_statvfs */
	{ AS(svr4_sys_fstatvfs_args), (sy_call_t *)svr4_sys_fstatvfs, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 104 = svr4_sys_fstatvfs */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 105 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 106 = nfssvc */
	{ AS(svr4_sys_waitsys_args), (sy_call_t *)svr4_sys_waitsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 107 = svr4_sys_waitsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 108 = sigsendsys */
	{ AS(svr4_sys_hrtsys_args), (sy_call_t *)svr4_sys_hrtsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 109 = svr4_sys_hrtsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 110 = acancel */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 111 = async */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 112 = priocntlsys */
	{ AS(svr4_sys_pathconf_args), (sy_call_t *)svr4_sys_pathconf, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 113 = svr4_sys_pathconf */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 114 = mincore */
	{ AS(svr4_sys_mmap_args), (sy_call_t *)svr4_sys_mmap, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 115 = svr4_sys_mmap */
	{ AS(mprotect_args), (sy_call_t *)sys_mprotect, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 116 = mprotect */
	{ AS(munmap_args), (sy_call_t *)sys_munmap, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 117 = munmap */
	{ AS(svr4_sys_fpathconf_args), (sy_call_t *)svr4_sys_fpathconf, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 118 = svr4_sys_fpathconf */
	{ 0, (sy_call_t *)sys_vfork, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },		/* 119 = vfork */
	{ AS(fchdir_args), (sy_call_t *)sys_fchdir, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 120 = fchdir */
	{ AS(readv_args), (sy_call_t *)sys_readv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 121 = readv */
	{ AS(writev_args), (sy_call_t *)sys_writev, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 122 = writev */
	{ AS(svr4_sys_xstat_args), (sy_call_t *)svr4_sys_xstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 123 = svr4_sys_xstat */
	{ AS(svr4_sys_lxstat_args), (sy_call_t *)svr4_sys_lxstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 124 = svr4_sys_lxstat */
	{ AS(svr4_sys_fxstat_args), (sy_call_t *)svr4_sys_fxstat, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 125 = svr4_sys_fxstat */
	{ AS(svr4_sys_xmknod_args), (sy_call_t *)svr4_sys_xmknod, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 126 = svr4_sys_xmknod */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 127 = clocal */
	{ AS(svr4_sys_setrlimit_args), (sy_call_t *)svr4_sys_setrlimit, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 128 = svr4_sys_setrlimit */
	{ AS(svr4_sys_getrlimit_args), (sy_call_t *)svr4_sys_getrlimit, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 129 = svr4_sys_getrlimit */
	{ AS(lchown_args), (sy_call_t *)sys_lchown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 130 = lchown */
	{ AS(svr4_sys_memcntl_args), (sy_call_t *)svr4_sys_memcntl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 131 = svr4_sys_memcntl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 132 = getpmsg */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 133 = putpmsg */
	{ AS(rename_args), (sy_call_t *)sys_rename, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 134 = rename */
	{ AS(svr4_sys_uname_args), (sy_call_t *)svr4_sys_uname, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 135 = svr4_sys_uname */
	{ AS(setegid_args), (sy_call_t *)sys_setegid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 136 = setegid */
	{ AS(svr4_sys_sysconfig_args), (sy_call_t *)svr4_sys_sysconfig, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 137 = svr4_sys_sysconfig */
	{ AS(adjtime_args), (sy_call_t *)sys_adjtime, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 138 = adjtime */
	{ AS(svr4_sys_systeminfo_args), (sy_call_t *)svr4_sys_systeminfo, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 139 = svr4_sys_systeminfo */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 140 = notused */
	{ AS(seteuid_args), (sy_call_t *)sys_seteuid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 141 = seteuid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 142 = vtrace */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 143 = { */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 144 = sigtimedwait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 145 = lwp_info */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 146 = yield */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 147 = lwp_sema_wait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 148 = lwp_sema_post */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 149 = lwp_sema_trywait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 150 = notused */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 151 = notused */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 152 = modctl */
	{ AS(svr4_sys_fchroot_args), (sy_call_t *)svr4_sys_fchroot, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 153 = svr4_sys_fchroot */
	{ AS(svr4_sys_utimes_args), (sy_call_t *)svr4_sys_utimes, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 154 = svr4_sys_utimes */
	{ 0, (sy_call_t *)svr4_sys_vhangup, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 155 = svr4_sys_vhangup */
	{ AS(svr4_sys_gettimeofday_args), (sy_call_t *)svr4_sys_gettimeofday, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 156 = svr4_sys_gettimeofday */
	{ AS(getitimer_args), (sy_call_t *)sys_getitimer, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 157 = getitimer */
	{ AS(setitimer_args), (sy_call_t *)sys_setitimer, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 158 = setitimer */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 159 = lwp_create */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 160 = lwp_exit */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 161 = lwp_suspend */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 162 = lwp_continue */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 163 = lwp_kill */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 164 = lwp_self */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 165 = lwp_getprivate */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 166 = lwp_setprivate */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 167 = lwp_wait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 168 = lwp_mutex_unlock */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 169 = lwp_mutex_lock */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 170 = lwp_cond_wait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 171 = lwp_cond_signal */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 172 = lwp_cond_broadcast */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 173 = { */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 174 = { */
	{ AS(svr4_sys_llseek_args), (sy_call_t *)svr4_sys_llseek, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 175 = svr4_sys_llseek */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 176 = inst_sync */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 177 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 178 = kaio */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 179 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 180 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 181 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 182 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 183 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 184 = tsolsys */
	{ AS(svr4_sys_acl_args), (sy_call_t *)svr4_sys_acl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 185 = svr4_sys_acl */
	{ AS(svr4_sys_auditsys_args), (sy_call_t *)svr4_sys_auditsys, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 186 = svr4_sys_auditsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 187 = processor_bind */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 188 = processor_info */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 189 = p_online */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 190 = sigqueue */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 191 = clock_gettime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 192 = clock_settime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 193 = clock_getres */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 194 = timer_create */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 195 = timer_delete */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 196 = timer_settime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 197 = timer_gettime */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 198 = timer_overrun */
	{ AS(nanosleep_args), (sy_call_t *)sys_nanosleep, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 199 = nanosleep */
	{ AS(svr4_sys_facl_args), (sy_call_t *)svr4_sys_facl, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 200 = svr4_sys_facl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 201 = door */
	{ AS(setreuid_args), (sy_call_t *)sys_setreuid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 202 = setreuid */
	{ AS(setregid_args), (sy_call_t *)sys_setregid, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 203 = setregid */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 204 = install_utrap */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 205 = signotify */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 206 = schedctl */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 207 = pset */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 208 = whoknows */
	{ AS(svr4_sys_resolvepath_args), (sy_call_t *)svr4_sys_resolvepath, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 209 = svr4_sys_resolvepath */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 210 = signotifywait */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 211 = lwp_sigredirect */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 212 = lwp_alarm */
	{ AS(svr4_sys_getdents64_args), (sy_call_t *)svr4_sys_getdents64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 213 = svr4_sys_getdents64 */
	{ AS(svr4_sys_mmap64_args), (sy_call_t *)svr4_sys_mmap64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 214 = svr4_sys_mmap64 */
	{ AS(svr4_sys_stat64_args), (sy_call_t *)svr4_sys_stat64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 215 = svr4_sys_stat64 */
	{ AS(svr4_sys_lstat64_args), (sy_call_t *)svr4_sys_lstat64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 216 = svr4_sys_lstat64 */
	{ AS(svr4_sys_fstat64_args), (sy_call_t *)svr4_sys_fstat64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 217 = svr4_sys_fstat64 */
	{ AS(svr4_sys_statvfs64_args), (sy_call_t *)svr4_sys_statvfs64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 218 = svr4_sys_statvfs64 */
	{ AS(svr4_sys_fstatvfs64_args), (sy_call_t *)svr4_sys_fstatvfs64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 219 = svr4_sys_fstatvfs64 */
	{ AS(svr4_sys_setrlimit64_args), (sy_call_t *)svr4_sys_setrlimit64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 220 = svr4_sys_setrlimit64 */
	{ AS(svr4_sys_getrlimit64_args), (sy_call_t *)svr4_sys_getrlimit64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 221 = svr4_sys_getrlimit64 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 222 = pread64 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 223 = pwrite64 */
	{ AS(svr4_sys_creat64_args), (sy_call_t *)svr4_sys_creat64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 224 = svr4_sys_creat64 */
	{ AS(svr4_sys_open64_args), (sy_call_t *)svr4_sys_open64, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 225 = svr4_sys_open64 */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 226 = rpcsys */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 227 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 228 = whoknows */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 229 = whoknows */
	{ AS(svr4_sys_socket_args), (sy_call_t *)svr4_sys_socket, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 230 = svr4_sys_socket */
	{ AS(socketpair_args), (sy_call_t *)sys_socketpair, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 231 = socketpair */
	{ AS(bind_args), (sy_call_t *)sys_bind, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 232 = bind */
	{ AS(listen_args), (sy_call_t *)sys_listen, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 233 = listen */
	{ AS(accept_args), (sy_call_t *)sys_accept, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 234 = accept */
	{ AS(connect_args), (sy_call_t *)sys_connect, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 235 = connect */
	{ AS(shutdown_args), (sy_call_t *)sys_shutdown, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 236 = shutdown */
	{ AS(svr4_sys_recv_args), (sy_call_t *)svr4_sys_recv, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 237 = svr4_sys_recv */
	{ AS(recvfrom_args), (sy_call_t *)sys_recvfrom, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 238 = recvfrom */
	{ AS(recvmsg_args), (sy_call_t *)sys_recvmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 239 = recvmsg */
	{ AS(svr4_sys_send_args), (sy_call_t *)svr4_sys_send, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 240 = svr4_sys_send */
	{ AS(sendmsg_args), (sy_call_t *)sys_sendmsg, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 241 = sendmsg */
	{ AS(svr4_sys_sendto_args), (sy_call_t *)svr4_sys_sendto, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 242 = svr4_sys_sendto */
	{ AS(getpeername_args), (sy_call_t *)sys_getpeername, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 243 = getpeername */
	{ AS(getsockname_args), (sy_call_t *)sys_getsockname, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 244 = getsockname */
	{ AS(getsockopt_args), (sy_call_t *)sys_getsockopt, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 245 = getsockopt */
	{ AS(setsockopt_args), (sy_call_t *)sys_setsockopt, AUE_NULL, NULL, 0, 0, 0, SY_THR_STATIC },	/* 246 = setsockopt */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 247 = sockconfig */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 248 = { */
	{ 0, (sy_call_t *)nosys, AUE_NULL, NULL, 0, 0, 0, SY_THR_ABSENT },			/* 249 = { */
};
