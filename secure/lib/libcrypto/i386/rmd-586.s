	# $FreeBSD: projects/armv6/secure/lib/libcrypto/i386/rmd-586.s 127326 2004-03-23 08:32:29Z markm $






	.file	"/usr/src/secure/lib/libcrypto/../../../crypto/openssl/crypto/ripemd/asm/rmd-586.s"
	.version	"01.01"
gcc2_compiled.:
.text
	.align 16
.globl ripemd160_block_asm_host_order
	.type	ripemd160_block_asm_host_order,@function
ripemd160_block_asm_host_order:
	movl	4(%esp),	%edx
	movl	8(%esp),	%eax
	pushl	%esi
	movl	(%edx),		%ecx
	pushl	%edi
	movl	4(%edx),	%esi
	pushl	%ebp
	movl	8(%edx),	%edi
	pushl	%ebx
	subl	$108,		%esp
.L000start:

	movl	(%eax),		%ebx
	movl	4(%eax),	%ebp
	movl	%ebx,		(%esp)
	movl	%ebp,		4(%esp)
	movl	8(%eax),	%ebx
	movl	12(%eax),	%ebp
	movl	%ebx,		8(%esp)
	movl	%ebp,		12(%esp)
	movl	16(%eax),	%ebx
	movl	20(%eax),	%ebp
	movl	%ebx,		16(%esp)
	movl	%ebp,		20(%esp)
	movl	24(%eax),	%ebx
	movl	28(%eax),	%ebp
	movl	%ebx,		24(%esp)
	movl	%ebp,		28(%esp)
	movl	32(%eax),	%ebx
	movl	36(%eax),	%ebp
	movl	%ebx,		32(%esp)
	movl	%ebp,		36(%esp)
	movl	40(%eax),	%ebx
	movl	44(%eax),	%ebp
	movl	%ebx,		40(%esp)
	movl	%ebp,		44(%esp)
	movl	48(%eax),	%ebx
	movl	52(%eax),	%ebp
	movl	%ebx,		48(%esp)
	movl	%ebp,		52(%esp)
	movl	56(%eax),	%ebx
	movl	60(%eax),	%ebp
	movl	%ebx,		56(%esp)
	movl	%ebp,		60(%esp)
	movl	%edi,		%eax
	movl	12(%edx),	%ebx
	movl	16(%edx),	%ebp

	xorl	%ebx,		%eax
	movl	(%esp),		%edx
	xorl	%esi,		%eax
	addl	%edx,		%ecx
	roll	$10,		%edi
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$11,		%ecx
	addl	%ebp,		%ecx

	xorl	%edi,		%eax
	movl	4(%esp),	%edx
	xorl	%ecx,		%eax
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$10,		%esi
	addl	%edx,		%ebp
	xorl	%esi,		%eax
	roll	$14,		%ebp
	addl	%ebx,		%ebp

	movl	8(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%edx,		%ebx
	roll	$10,		%ecx
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$15,		%ebx
	addl	%edi,		%ebx

	xorl	%ecx,		%eax
	movl	12(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$10,		%ebp
	addl	%edx,		%edi
	xorl	%ebp,		%eax
	roll	$12,		%edi
	addl	%esi,		%edi

	movl	16(%esp),	%edx
	xorl	%edi,		%eax
	addl	%edx,		%esi
	roll	$10,		%ebx
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$5,		%esi
	addl	%ecx,		%esi

	xorl	%ebx,		%eax
	movl	20(%esp),	%edx
	xorl	%esi,		%eax
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$10,		%edi
	addl	%edx,		%ecx
	xorl	%edi,		%eax
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	movl	24(%esp),	%edx
	xorl	%ecx,		%eax
	addl	%edx,		%ebp
	roll	$10,		%esi
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$7,		%ebp
	addl	%ebx,		%ebp

	xorl	%esi,		%eax
	movl	28(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$10,		%ecx
	addl	%edx,		%ebx
	xorl	%ecx,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	movl	32(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%edx,		%edi
	roll	$10,		%ebp
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$11,		%edi
	addl	%esi,		%edi

	xorl	%ebp,		%eax
	movl	36(%esp),	%edx
	xorl	%edi,		%eax
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$10,		%ebx
	addl	%edx,		%esi
	xorl	%ebx,		%eax
	roll	$13,		%esi
	addl	%ecx,		%esi

	movl	40(%esp),	%edx
	xorl	%esi,		%eax
	addl	%edx,		%ecx
	roll	$10,		%edi
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	xorl	%edi,		%eax
	movl	44(%esp),	%edx
	xorl	%ecx,		%eax
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$10,		%esi
	addl	%edx,		%ebp
	xorl	%esi,		%eax
	roll	$15,		%ebp
	addl	%ebx,		%ebp

	movl	48(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%edx,		%ebx
	roll	$10,		%ecx
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$6,		%ebx
	addl	%edi,		%ebx

	xorl	%ecx,		%eax
	movl	52(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$10,		%ebp
	addl	%edx,		%edi
	xorl	%ebp,		%eax
	roll	$7,		%edi
	addl	%esi,		%edi

	movl	56(%esp),	%edx
	xorl	%edi,		%eax
	addl	%edx,		%esi
	roll	$10,		%ebx
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$9,		%esi
	addl	%ecx,		%esi

	xorl	%ebx,		%eax
	movl	60(%esp),	%edx
	xorl	%esi,		%eax
	addl	%eax,		%ecx
	movl	$-1,		%eax
	roll	$10,		%edi
	addl	%edx,		%ecx
	movl	28(%esp),	%edx
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	addl	%edx,		%ebp
	movl	%esi,		%edx
	subl	%ecx,		%eax
	andl	%ecx,		%edx
	andl	%edi,		%eax
	orl	%eax,		%edx
	movl	16(%esp),	%eax
	roll	$10,		%esi
	leal	1518500249(%ebp,%edx,1),%ebp
	movl	$-1,		%edx
	roll	$7,		%ebp
	addl	%ebx,		%ebp

	addl	%eax,		%ebx
	movl	%ecx,		%eax
	subl	%ebp,		%edx
	andl	%ebp,		%eax
	andl	%esi,		%edx
	orl	%edx,		%eax
	movl	52(%esp),	%edx
	roll	$10,		%ecx
	leal	1518500249(%ebx,%eax,1),%ebx
	movl	$-1,		%eax
	roll	$6,		%ebx
	addl	%edi,		%ebx

	addl	%edx,		%edi
	movl	%ebp,		%edx
	subl	%ebx,		%eax
	andl	%ebx,		%edx
	andl	%ecx,		%eax
	orl	%eax,		%edx
	movl	4(%esp),	%eax
	roll	$10,		%ebp
	leal	1518500249(%edi,%edx,1),%edi
	movl	$-1,		%edx
	roll	$8,		%edi
	addl	%esi,		%edi

	addl	%eax,		%esi
	movl	%ebx,		%eax
	subl	%edi,		%edx
	andl	%edi,		%eax
	andl	%ebp,		%edx
	orl	%edx,		%eax
	movl	40(%esp),	%edx
	roll	$10,		%ebx
	leal	1518500249(%esi,%eax,1),%esi
	movl	$-1,		%eax
	roll	$13,		%esi
	addl	%ecx,		%esi

	addl	%edx,		%ecx
	movl	%edi,		%edx
	subl	%esi,		%eax
	andl	%esi,		%edx
	andl	%ebx,		%eax
	orl	%eax,		%edx
	movl	24(%esp),	%eax
	roll	$10,		%edi
	leal	1518500249(%ecx,%edx,1),%ecx
	movl	$-1,		%edx
	roll	$11,		%ecx
	addl	%ebp,		%ecx

	addl	%eax,		%ebp
	movl	%esi,		%eax
	subl	%ecx,		%edx
	andl	%ecx,		%eax
	andl	%edi,		%edx
	orl	%edx,		%eax
	movl	60(%esp),	%edx
	roll	$10,		%esi
	leal	1518500249(%ebp,%eax,1),%ebp
	movl	$-1,		%eax
	roll	$9,		%ebp
	addl	%ebx,		%ebp

	addl	%edx,		%ebx
	movl	%ecx,		%edx
	subl	%ebp,		%eax
	andl	%ebp,		%edx
	andl	%esi,		%eax
	orl	%eax,		%edx
	movl	12(%esp),	%eax
	roll	$10,		%ecx
	leal	1518500249(%ebx,%edx,1),%ebx
	movl	$-1,		%edx
	roll	$7,		%ebx
	addl	%edi,		%ebx

	addl	%eax,		%edi
	movl	%ebp,		%eax
	subl	%ebx,		%edx
	andl	%ebx,		%eax
	andl	%ecx,		%edx
	orl	%edx,		%eax
	movl	48(%esp),	%edx
	roll	$10,		%ebp
	leal	1518500249(%edi,%eax,1),%edi
	movl	$-1,		%eax
	roll	$15,		%edi
	addl	%esi,		%edi

	addl	%edx,		%esi
	movl	%ebx,		%edx
	subl	%edi,		%eax
	andl	%edi,		%edx
	andl	%ebp,		%eax
	orl	%eax,		%edx
	movl	(%esp),		%eax
	roll	$10,		%ebx
	leal	1518500249(%esi,%edx,1),%esi
	movl	$-1,		%edx
	roll	$7,		%esi
	addl	%ecx,		%esi

	addl	%eax,		%ecx
	movl	%edi,		%eax
	subl	%esi,		%edx
	andl	%esi,		%eax
	andl	%ebx,		%edx
	orl	%edx,		%eax
	movl	36(%esp),	%edx
	roll	$10,		%edi
	leal	1518500249(%ecx,%eax,1),%ecx
	movl	$-1,		%eax
	roll	$12,		%ecx
	addl	%ebp,		%ecx

	addl	%edx,		%ebp
	movl	%esi,		%edx
	subl	%ecx,		%eax
	andl	%ecx,		%edx
	andl	%edi,		%eax
	orl	%eax,		%edx
	movl	20(%esp),	%eax
	roll	$10,		%esi
	leal	1518500249(%ebp,%edx,1),%ebp
	movl	$-1,		%edx
	roll	$15,		%ebp
	addl	%ebx,		%ebp

	addl	%eax,		%ebx
	movl	%ecx,		%eax
	subl	%ebp,		%edx
	andl	%ebp,		%eax
	andl	%esi,		%edx
	orl	%edx,		%eax
	movl	8(%esp),	%edx
	roll	$10,		%ecx
	leal	1518500249(%ebx,%eax,1),%ebx
	movl	$-1,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	addl	%edx,		%edi
	movl	%ebp,		%edx
	subl	%ebx,		%eax
	andl	%ebx,		%edx
	andl	%ecx,		%eax
	orl	%eax,		%edx
	movl	56(%esp),	%eax
	roll	$10,		%ebp
	leal	1518500249(%edi,%edx,1),%edi
	movl	$-1,		%edx
	roll	$11,		%edi
	addl	%esi,		%edi

	addl	%eax,		%esi
	movl	%ebx,		%eax
	subl	%edi,		%edx
	andl	%edi,		%eax
	andl	%ebp,		%edx
	orl	%edx,		%eax
	movl	44(%esp),	%edx
	roll	$10,		%ebx
	leal	1518500249(%esi,%eax,1),%esi
	movl	$-1,		%eax
	roll	$7,		%esi
	addl	%ecx,		%esi

	addl	%edx,		%ecx
	movl	%edi,		%edx
	subl	%esi,		%eax
	andl	%esi,		%edx
	andl	%ebx,		%eax
	orl	%eax,		%edx
	movl	32(%esp),	%eax
	roll	$10,		%edi
	leal	1518500249(%ecx,%edx,1),%ecx
	movl	$-1,		%edx
	roll	$13,		%ecx
	addl	%ebp,		%ecx

	addl	%eax,		%ebp
	movl	%esi,		%eax
	subl	%ecx,		%edx
	andl	%ecx,		%eax
	andl	%edi,		%edx
	orl	%edx,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	1518500249(%ebp,%eax,1),%ebp
	subl	%ecx,		%edx
	roll	$12,		%ebp
	addl	%ebx,		%ebp

	movl	12(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%ebx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1859775393(%ebx,%edx,1),%ebx
	subl	%ebp,		%eax
	roll	$11,		%ebx
	addl	%edi,		%ebx

	movl	40(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%edi
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1859775393(%edi,%eax,1),%edi
	subl	%ebx,		%edx
	roll	$13,		%edi
	addl	%esi,		%edi

	movl	56(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%esi
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1859775393(%esi,%edx,1),%esi
	subl	%edi,		%eax
	roll	$6,		%esi
	addl	%ecx,		%esi

	movl	16(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ecx
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1859775393(%ecx,%eax,1),%ecx
	subl	%esi,		%edx
	roll	$7,		%ecx
	addl	%ebp,		%ecx

	movl	36(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebp
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	1859775393(%ebp,%edx,1),%ebp
	subl	%ecx,		%eax
	roll	$14,		%ebp
	addl	%ebx,		%ebp

	movl	60(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%ebx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	1859775393(%ebx,%eax,1),%ebx
	subl	%ebp,		%edx
	roll	$9,		%ebx
	addl	%edi,		%ebx

	movl	32(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%edi
	xorl	%ecx,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebp
	leal	1859775393(%edi,%edx,1),%edi
	subl	%ebx,		%eax
	roll	$13,		%edi
	addl	%esi,		%edi

	movl	4(%esp),	%edx
	orl	%edi,		%eax
	addl	%edx,		%esi
	xorl	%ebp,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebx
	leal	1859775393(%esi,%eax,1),%esi
	subl	%edi,		%edx
	roll	$15,		%esi
	addl	%ecx,		%esi

	movl	8(%esp),	%eax
	orl	%esi,		%edx
	addl	%eax,		%ecx
	xorl	%ebx,		%edx
	movl	$-1,		%eax
	roll	$10,		%edi
	leal	1859775393(%ecx,%edx,1),%ecx
	subl	%esi,		%eax
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	movl	28(%esp),	%edx
	orl	%ecx,		%eax
	addl	%edx,		%ebp
	xorl	%edi,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	1859775393(%ebp,%eax,1),%ebp
	subl	%ecx,		%edx
	roll	$8,		%ebp
	addl	%ebx,		%ebp

	movl	(%esp),		%eax
	orl	%ebp,		%edx
	addl	%eax,		%ebx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1859775393(%ebx,%edx,1),%ebx
	subl	%ebp,		%eax
	roll	$13,		%ebx
	addl	%edi,		%ebx

	movl	24(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%edi
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1859775393(%edi,%eax,1),%edi
	subl	%ebx,		%edx
	roll	$6,		%edi
	addl	%esi,		%edi

	movl	52(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%esi
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1859775393(%esi,%edx,1),%esi
	subl	%edi,		%eax
	roll	$5,		%esi
	addl	%ecx,		%esi

	movl	44(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ecx
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1859775393(%ecx,%eax,1),%ecx
	subl	%esi,		%edx
	roll	$12,		%ecx
	addl	%ebp,		%ecx

	movl	20(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebp
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	1859775393(%ebp,%edx,1),%ebp
	subl	%ecx,		%eax
	roll	$7,		%ebp
	addl	%ebx,		%ebp

	movl	48(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%ebx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	1859775393(%ebx,%eax,1),%ebx
	movl	%ecx,		%eax
	roll	$5,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	4(%esp),	%eax
	roll	$10,		%ebp
	leal	2400959708(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$11,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	36(%esp),	%eax
	roll	$10,		%ebx
	leal	2400959708(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$12,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	44(%esp),	%eax
	roll	$10,		%edi
	leal	2400959708(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	40(%esp),	%eax
	roll	$10,		%esi
	leal	2400959708(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$15,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	(%esp),		%eax
	roll	$10,		%ecx
	leal	2400959708(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$14,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	32(%esp),	%eax
	roll	$10,		%ebp
	leal	2400959708(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$15,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	48(%esp),	%eax
	roll	$10,		%ebx
	leal	2400959708(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$9,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	16(%esp),	%eax
	roll	$10,		%edi
	leal	2400959708(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	52(%esp),	%eax
	roll	$10,		%esi
	leal	2400959708(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$9,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	12(%esp),	%eax
	roll	$10,		%ecx
	leal	2400959708(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$14,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	28(%esp),	%eax
	roll	$10,		%ebp
	leal	2400959708(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$5,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	60(%esp),	%eax
	roll	$10,		%ebx
	leal	2400959708(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$6,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	56(%esp),	%eax
	roll	$10,		%edi
	leal	2400959708(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	20(%esp),	%eax
	roll	$10,		%esi
	leal	2400959708(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$6,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	24(%esp),	%eax
	roll	$10,		%ecx
	leal	2400959708(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$5,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	8(%esp),	%eax
	roll	$10,		%ebp
	leal	2400959708(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	subl	%ebp,		%edx
	roll	$12,		%edi
	addl	%esi,		%edi

	movl	16(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%esi
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	2840853838(%esi,%edx,1),%esi
	subl	%ebx,		%eax
	roll	$9,		%esi
	addl	%ecx,		%esi

	movl	(%esp),		%edx
	orl	%edi,		%eax
	addl	%edx,		%ecx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	2840853838(%ecx,%eax,1),%ecx
	subl	%edi,		%edx
	roll	$15,		%ecx
	addl	%ebp,		%ecx

	movl	20(%esp),	%eax
	orl	%esi,		%edx
	addl	%eax,		%ebp
	xorl	%ecx,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	2840853838(%ebp,%edx,1),%ebp
	subl	%esi,		%eax
	roll	$5,		%ebp
	addl	%ebx,		%ebp

	movl	36(%esp),	%edx
	orl	%ecx,		%eax
	addl	%edx,		%ebx
	xorl	%ebp,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	2840853838(%ebx,%eax,1),%ebx
	subl	%ecx,		%edx
	roll	$11,		%ebx
	addl	%edi,		%ebx

	movl	28(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%edi
	xorl	%ebx,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebp
	leal	2840853838(%edi,%edx,1),%edi
	subl	%ebp,		%eax
	roll	$6,		%edi
	addl	%esi,		%edi

	movl	48(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%esi
	xorl	%edi,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebx
	leal	2840853838(%esi,%eax,1),%esi
	subl	%ebx,		%edx
	roll	$8,		%esi
	addl	%ecx,		%esi

	movl	8(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%ecx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%edi
	leal	2840853838(%ecx,%edx,1),%ecx
	subl	%edi,		%eax
	roll	$13,		%ecx
	addl	%ebp,		%ecx

	movl	40(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ebp
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	2840853838(%ebp,%eax,1),%ebp
	subl	%esi,		%edx
	roll	$12,		%ebp
	addl	%ebx,		%ebp

	movl	56(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebx
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	2840853838(%ebx,%edx,1),%ebx
	subl	%ecx,		%eax
	roll	$5,		%ebx
	addl	%edi,		%ebx

	movl	4(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%edi
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	2840853838(%edi,%eax,1),%edi
	subl	%ebp,		%edx
	roll	$12,		%edi
	addl	%esi,		%edi

	movl	12(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%esi
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	2840853838(%esi,%edx,1),%esi
	subl	%ebx,		%eax
	roll	$13,		%esi
	addl	%ecx,		%esi

	movl	32(%esp),	%edx
	orl	%edi,		%eax
	addl	%edx,		%ecx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	2840853838(%ecx,%eax,1),%ecx
	subl	%edi,		%edx
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	movl	44(%esp),	%eax
	orl	%esi,		%edx
	addl	%eax,		%ebp
	xorl	%ecx,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	2840853838(%ebp,%edx,1),%ebp
	subl	%esi,		%eax
	roll	$11,		%ebp
	addl	%ebx,		%ebp

	movl	24(%esp),	%edx
	orl	%ecx,		%eax
	addl	%edx,		%ebx
	xorl	%ebp,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	2840853838(%ebx,%eax,1),%ebx
	subl	%ecx,		%edx
	roll	$8,		%ebx
	addl	%edi,		%ebx

	movl	60(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%edi
	xorl	%ebx,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebp
	leal	2840853838(%edi,%edx,1),%edi
	subl	%ebp,		%eax
	roll	$5,		%edi
	addl	%esi,		%edi

	movl	52(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%esi
	xorl	%edi,		%eax
	movl	128(%esp),	%edx
	roll	$10,		%ebx
	leal	2840853838(%esi,%eax,1),%esi
	movl	%ecx,		64(%esp)
	roll	$6,		%esi
	addl	%ecx,		%esi
	movl	(%edx),		%ecx
	movl	%esi,		68(%esp)
	movl	%edi,		72(%esp)
	movl	4(%edx),	%esi
	movl	%ebx,		76(%esp)
	movl	8(%edx),	%edi
	movl	%ebp,		80(%esp)
	movl	12(%edx),	%ebx
	movl	16(%edx),	%ebp

	movl	$-1,		%edx
	subl	%ebx,		%edx
	movl	20(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%ecx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%edi
	leal	1352829926(%ecx,%edx,1),%ecx
	subl	%edi,		%eax
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	movl	56(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ebp
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	1352829926(%ebp,%eax,1),%ebp
	subl	%esi,		%edx
	roll	$9,		%ebp
	addl	%ebx,		%ebp

	movl	28(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebx
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1352829926(%ebx,%edx,1),%ebx
	subl	%ecx,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	movl	(%esp),		%edx
	orl	%ebp,		%eax
	addl	%edx,		%edi
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1352829926(%edi,%eax,1),%edi
	subl	%ebp,		%edx
	roll	$11,		%edi
	addl	%esi,		%edi

	movl	36(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%esi
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1352829926(%esi,%edx,1),%esi
	subl	%ebx,		%eax
	roll	$13,		%esi
	addl	%ecx,		%esi

	movl	8(%esp),	%edx
	orl	%edi,		%eax
	addl	%edx,		%ecx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1352829926(%ecx,%eax,1),%ecx
	subl	%edi,		%edx
	roll	$15,		%ecx
	addl	%ebp,		%ecx

	movl	44(%esp),	%eax
	orl	%esi,		%edx
	addl	%eax,		%ebp
	xorl	%ecx,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	1352829926(%ebp,%edx,1),%ebp
	subl	%esi,		%eax
	roll	$15,		%ebp
	addl	%ebx,		%ebp

	movl	16(%esp),	%edx
	orl	%ecx,		%eax
	addl	%edx,		%ebx
	xorl	%ebp,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	1352829926(%ebx,%eax,1),%ebx
	subl	%ecx,		%edx
	roll	$5,		%ebx
	addl	%edi,		%ebx

	movl	52(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%edi
	xorl	%ebx,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebp
	leal	1352829926(%edi,%edx,1),%edi
	subl	%ebp,		%eax
	roll	$7,		%edi
	addl	%esi,		%edi

	movl	24(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%esi
	xorl	%edi,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebx
	leal	1352829926(%esi,%eax,1),%esi
	subl	%ebx,		%edx
	roll	$7,		%esi
	addl	%ecx,		%esi

	movl	60(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%ecx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%edi
	leal	1352829926(%ecx,%edx,1),%ecx
	subl	%edi,		%eax
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	movl	32(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ebp
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	1352829926(%ebp,%eax,1),%ebp
	subl	%esi,		%edx
	roll	$11,		%ebp
	addl	%ebx,		%ebp

	movl	4(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebx
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1352829926(%ebx,%edx,1),%ebx
	subl	%ecx,		%eax
	roll	$14,		%ebx
	addl	%edi,		%ebx

	movl	40(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%edi
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1352829926(%edi,%eax,1),%edi
	subl	%ebp,		%edx
	roll	$14,		%edi
	addl	%esi,		%edi

	movl	12(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%esi
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1352829926(%esi,%edx,1),%esi
	subl	%ebx,		%eax
	roll	$12,		%esi
	addl	%ecx,		%esi

	movl	48(%esp),	%edx
	orl	%edi,		%eax
	addl	%edx,		%ecx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1352829926(%ecx,%eax,1),%ecx
	movl	%edi,		%eax
	roll	$6,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	24(%esp),	%eax
	roll	$10,		%esi
	leal	1548603684(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$9,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	44(%esp),	%eax
	roll	$10,		%ecx
	leal	1548603684(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$13,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	12(%esp),	%eax
	roll	$10,		%ebp
	leal	1548603684(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$15,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	28(%esp),	%eax
	roll	$10,		%ebx
	leal	1548603684(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$7,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	(%esp),		%eax
	roll	$10,		%edi
	leal	1548603684(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$12,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	52(%esp),	%eax
	roll	$10,		%esi
	leal	1548603684(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$8,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	20(%esp),	%eax
	roll	$10,		%ecx
	leal	1548603684(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	40(%esp),	%eax
	roll	$10,		%ebp
	leal	1548603684(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$11,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	56(%esp),	%eax
	roll	$10,		%ebx
	leal	1548603684(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$7,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	60(%esp),	%eax
	roll	$10,		%edi
	leal	1548603684(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$7,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	32(%esp),	%eax
	roll	$10,		%esi
	leal	1548603684(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	movl	%esi,		%eax
	roll	$12,		%ebp
	addl	%ebx,		%ebp

	subl	%esi,		%edx
	andl	%ebp,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	48(%esp),	%eax
	roll	$10,		%ecx
	leal	1548603684(%ebx,%edx),%ebx
	movl	$-1,		%edx
	addl	%eax,		%ebx
	movl	%ecx,		%eax
	roll	$7,		%ebx
	addl	%edi,		%ebx

	subl	%ecx,		%edx
	andl	%ebx,		%eax
	andl	%ebp,		%edx
	orl	%eax,		%edx
	movl	16(%esp),	%eax
	roll	$10,		%ebp
	leal	1548603684(%edi,%edx),%edi
	movl	$-1,		%edx
	addl	%eax,		%edi
	movl	%ebp,		%eax
	roll	$6,		%edi
	addl	%esi,		%edi

	subl	%ebp,		%edx
	andl	%edi,		%eax
	andl	%ebx,		%edx
	orl	%eax,		%edx
	movl	36(%esp),	%eax
	roll	$10,		%ebx
	leal	1548603684(%esi,%edx),%esi
	movl	$-1,		%edx
	addl	%eax,		%esi
	movl	%ebx,		%eax
	roll	$15,		%esi
	addl	%ecx,		%esi

	subl	%ebx,		%edx
	andl	%esi,		%eax
	andl	%edi,		%edx
	orl	%eax,		%edx
	movl	4(%esp),	%eax
	roll	$10,		%edi
	leal	1548603684(%ecx,%edx),%ecx
	movl	$-1,		%edx
	addl	%eax,		%ecx
	movl	%edi,		%eax
	roll	$13,		%ecx
	addl	%ebp,		%ecx

	subl	%edi,		%edx
	andl	%ecx,		%eax
	andl	%esi,		%edx
	orl	%eax,		%edx
	movl	8(%esp),	%eax
	roll	$10,		%esi
	leal	1548603684(%ebp,%edx),%ebp
	movl	$-1,		%edx
	addl	%eax,		%ebp
	subl	%ecx,		%edx
	roll	$11,		%ebp
	addl	%ebx,		%ebp

	movl	60(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%ebx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1836072691(%ebx,%edx,1),%ebx
	subl	%ebp,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	movl	20(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%edi
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1836072691(%edi,%eax,1),%edi
	subl	%ebx,		%edx
	roll	$7,		%edi
	addl	%esi,		%edi

	movl	4(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%esi
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1836072691(%esi,%edx,1),%esi
	subl	%edi,		%eax
	roll	$15,		%esi
	addl	%ecx,		%esi

	movl	12(%esp),	%edx
	orl	%esi,		%eax
	addl	%edx,		%ecx
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1836072691(%ecx,%eax,1),%ecx
	subl	%esi,		%edx
	roll	$11,		%ecx
	addl	%ebp,		%ecx

	movl	28(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebp
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	1836072691(%ebp,%edx,1),%ebp
	subl	%ecx,		%eax
	roll	$8,		%ebp
	addl	%ebx,		%ebp

	movl	56(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%ebx
	xorl	%esi,		%eax
	movl	$-1,		%edx
	roll	$10,		%ecx
	leal	1836072691(%ebx,%eax,1),%ebx
	subl	%ebp,		%edx
	roll	$6,		%ebx
	addl	%edi,		%ebx

	movl	24(%esp),	%eax
	orl	%ebx,		%edx
	addl	%eax,		%edi
	xorl	%ecx,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebp
	leal	1836072691(%edi,%edx,1),%edi
	subl	%ebx,		%eax
	roll	$6,		%edi
	addl	%esi,		%edi

	movl	36(%esp),	%edx
	orl	%edi,		%eax
	addl	%edx,		%esi
	xorl	%ebp,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebx
	leal	1836072691(%esi,%eax,1),%esi
	subl	%edi,		%edx
	roll	$14,		%esi
	addl	%ecx,		%esi

	movl	44(%esp),	%eax
	orl	%esi,		%edx
	addl	%eax,		%ecx
	xorl	%ebx,		%edx
	movl	$-1,		%eax
	roll	$10,		%edi
	leal	1836072691(%ecx,%edx,1),%ecx
	subl	%esi,		%eax
	roll	$12,		%ecx
	addl	%ebp,		%ecx

	movl	32(%esp),	%edx
	orl	%ecx,		%eax
	addl	%edx,		%ebp
	xorl	%edi,		%eax
	movl	$-1,		%edx
	roll	$10,		%esi
	leal	1836072691(%ebp,%eax,1),%ebp
	subl	%ecx,		%edx
	roll	$13,		%ebp
	addl	%ebx,		%ebp

	movl	48(%esp),	%eax
	orl	%ebp,		%edx
	addl	%eax,		%ebx
	xorl	%esi,		%edx
	movl	$-1,		%eax
	roll	$10,		%ecx
	leal	1836072691(%ebx,%edx,1),%ebx
	subl	%ebp,		%eax
	roll	$5,		%ebx
	addl	%edi,		%ebx

	movl	8(%esp),	%edx
	orl	%ebx,		%eax
	addl	%edx,		%edi
	xorl	%ecx,		%eax
	movl	$-1,		%edx
	roll	$10,		%ebp
	leal	1836072691(%edi,%eax,1),%edi
	subl	%ebx,		%edx
	roll	$14,		%edi
	addl	%esi,		%edi

	movl	40(%esp),	%eax
	orl	%edi,		%edx
	addl	%eax,		%esi
	xorl	%ebp,		%edx
	movl	$-1,		%eax
	roll	$10,		%ebx
	leal	1836072691(%esi,%edx,1),%esi
	subl	%edi,		%eax
	roll	$13,		%esi
	addl	%ecx,		%esi

	movl	(%esp),		%edx
	orl	%esi,		%eax
	addl	%edx,		%ecx
	xorl	%ebx,		%eax
	movl	$-1,		%edx
	roll	$10,		%edi
	leal	1836072691(%ecx,%eax,1),%ecx
	subl	%esi,		%edx
	roll	$13,		%ecx
	addl	%ebp,		%ecx

	movl	16(%esp),	%eax
	orl	%ecx,		%edx
	addl	%eax,		%ebp
	xorl	%edi,		%edx
	movl	$-1,		%eax
	roll	$10,		%esi
	leal	1836072691(%ebp,%edx,1),%ebp
	subl	%ecx,		%eax
	roll	$7,		%ebp
	addl	%ebx,		%ebp

	movl	52(%esp),	%edx
	orl	%ebp,		%eax
	addl	%edx,		%ebx
	xorl	%esi,		%eax
	movl	32(%esp),	%edx
	roll	$10,		%ecx
	leal	1836072691(%ebx,%eax,1),%ebx
	movl	$-1,		%eax
	roll	$5,		%ebx
	addl	%edi,		%ebx

	addl	%edx,		%edi
	movl	%ebp,		%edx
	subl	%ebx,		%eax
	andl	%ebx,		%edx
	andl	%ecx,		%eax
	orl	%eax,		%edx
	movl	24(%esp),	%eax
	roll	$10,		%ebp
	leal	2053994217(%edi,%edx,1),%edi
	movl	$-1,		%edx
	roll	$15,		%edi
	addl	%esi,		%edi

	addl	%eax,		%esi
	movl	%ebx,		%eax
	subl	%edi,		%edx
	andl	%edi,		%eax
	andl	%ebp,		%edx
	orl	%edx,		%eax
	movl	16(%esp),	%edx
	roll	$10,		%ebx
	leal	2053994217(%esi,%eax,1),%esi
	movl	$-1,		%eax
	roll	$5,		%esi
	addl	%ecx,		%esi

	addl	%edx,		%ecx
	movl	%edi,		%edx
	subl	%esi,		%eax
	andl	%esi,		%edx
	andl	%ebx,		%eax
	orl	%eax,		%edx
	movl	4(%esp),	%eax
	roll	$10,		%edi
	leal	2053994217(%ecx,%edx,1),%ecx
	movl	$-1,		%edx
	roll	$8,		%ecx
	addl	%ebp,		%ecx

	addl	%eax,		%ebp
	movl	%esi,		%eax
	subl	%ecx,		%edx
	andl	%ecx,		%eax
	andl	%edi,		%edx
	orl	%edx,		%eax
	movl	12(%esp),	%edx
	roll	$10,		%esi
	leal	2053994217(%ebp,%eax,1),%ebp
	movl	$-1,		%eax
	roll	$11,		%ebp
	addl	%ebx,		%ebp

	addl	%edx,		%ebx
	movl	%ecx,		%edx
	subl	%ebp,		%eax
	andl	%ebp,		%edx
	andl	%esi,		%eax
	orl	%eax,		%edx
	movl	44(%esp),	%eax
	roll	$10,		%ecx
	leal	2053994217(%ebx,%edx,1),%ebx
	movl	$-1,		%edx
	roll	$14,		%ebx
	addl	%edi,		%ebx

	addl	%eax,		%edi
	movl	%ebp,		%eax
	subl	%ebx,		%edx
	andl	%ebx,		%eax
	andl	%ecx,		%edx
	orl	%edx,		%eax
	movl	60(%esp),	%edx
	roll	$10,		%ebp
	leal	2053994217(%edi,%eax,1),%edi
	movl	$-1,		%eax
	roll	$14,		%edi
	addl	%esi,		%edi

	addl	%edx,		%esi
	movl	%ebx,		%edx
	subl	%edi,		%eax
	andl	%edi,		%edx
	andl	%ebp,		%eax
	orl	%eax,		%edx
	movl	(%esp),		%eax
	roll	$10,		%ebx
	leal	2053994217(%esi,%edx,1),%esi
	movl	$-1,		%edx
	roll	$6,		%esi
	addl	%ecx,		%esi

	addl	%eax,		%ecx
	movl	%edi,		%eax
	subl	%esi,		%edx
	andl	%esi,		%eax
	andl	%ebx,		%edx
	orl	%edx,		%eax
	movl	20(%esp),	%edx
	roll	$10,		%edi
	leal	2053994217(%ecx,%eax,1),%ecx
	movl	$-1,		%eax
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	addl	%edx,		%ebp
	movl	%esi,		%edx
	subl	%ecx,		%eax
	andl	%ecx,		%edx
	andl	%edi,		%eax
	orl	%eax,		%edx
	movl	48(%esp),	%eax
	roll	$10,		%esi
	leal	2053994217(%ebp,%edx,1),%ebp
	movl	$-1,		%edx
	roll	$6,		%ebp
	addl	%ebx,		%ebp

	addl	%eax,		%ebx
	movl	%ecx,		%eax
	subl	%ebp,		%edx
	andl	%ebp,		%eax
	andl	%esi,		%edx
	orl	%edx,		%eax
	movl	8(%esp),	%edx
	roll	$10,		%ecx
	leal	2053994217(%ebx,%eax,1),%ebx
	movl	$-1,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	addl	%edx,		%edi
	movl	%ebp,		%edx
	subl	%ebx,		%eax
	andl	%ebx,		%edx
	andl	%ecx,		%eax
	orl	%eax,		%edx
	movl	52(%esp),	%eax
	roll	$10,		%ebp
	leal	2053994217(%edi,%edx,1),%edi
	movl	$-1,		%edx
	roll	$12,		%edi
	addl	%esi,		%edi

	addl	%eax,		%esi
	movl	%ebx,		%eax
	subl	%edi,		%edx
	andl	%edi,		%eax
	andl	%ebp,		%edx
	orl	%edx,		%eax
	movl	36(%esp),	%edx
	roll	$10,		%ebx
	leal	2053994217(%esi,%eax,1),%esi
	movl	$-1,		%eax
	roll	$9,		%esi
	addl	%ecx,		%esi

	addl	%edx,		%ecx
	movl	%edi,		%edx
	subl	%esi,		%eax
	andl	%esi,		%edx
	andl	%ebx,		%eax
	orl	%eax,		%edx
	movl	28(%esp),	%eax
	roll	$10,		%edi
	leal	2053994217(%ecx,%edx,1),%ecx
	movl	$-1,		%edx
	roll	$12,		%ecx
	addl	%ebp,		%ecx

	addl	%eax,		%ebp
	movl	%esi,		%eax
	subl	%ecx,		%edx
	andl	%ecx,		%eax
	andl	%edi,		%edx
	orl	%edx,		%eax
	movl	40(%esp),	%edx
	roll	$10,		%esi
	leal	2053994217(%ebp,%eax,1),%ebp
	movl	$-1,		%eax
	roll	$5,		%ebp
	addl	%ebx,		%ebp

	addl	%edx,		%ebx
	movl	%ecx,		%edx
	subl	%ebp,		%eax
	andl	%ebp,		%edx
	andl	%esi,		%eax
	orl	%eax,		%edx
	movl	56(%esp),	%eax
	roll	$10,		%ecx
	leal	2053994217(%ebx,%edx,1),%ebx
	movl	$-1,		%edx
	roll	$15,		%ebx
	addl	%edi,		%ebx

	addl	%eax,		%edi
	movl	%ebp,		%eax
	subl	%ebx,		%edx
	andl	%ebx,		%eax
	andl	%ecx,		%edx
	orl	%eax,		%edx
	movl	%ebx,		%eax
	roll	$10,		%ebp
	leal	2053994217(%edi,%edx,1),%edi
	xorl	%ebp,		%eax
	roll	$8,		%edi
	addl	%esi,		%edi

	movl	48(%esp),	%edx
	xorl	%edi,		%eax
	addl	%edx,		%esi
	roll	$10,		%ebx
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$8,		%esi
	addl	%ecx,		%esi

	xorl	%ebx,		%eax
	movl	60(%esp),	%edx
	xorl	%esi,		%eax
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$10,		%edi
	addl	%edx,		%ecx
	xorl	%edi,		%eax
	roll	$5,		%ecx
	addl	%ebp,		%ecx

	movl	40(%esp),	%edx
	xorl	%ecx,		%eax
	addl	%edx,		%ebp
	roll	$10,		%esi
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$12,		%ebp
	addl	%ebx,		%ebp

	xorl	%esi,		%eax
	movl	16(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$10,		%ecx
	addl	%edx,		%ebx
	xorl	%ecx,		%eax
	roll	$9,		%ebx
	addl	%edi,		%ebx

	movl	4(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%edx,		%edi
	roll	$10,		%ebp
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$12,		%edi
	addl	%esi,		%edi

	xorl	%ebp,		%eax
	movl	20(%esp),	%edx
	xorl	%edi,		%eax
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$10,		%ebx
	addl	%edx,		%esi
	xorl	%ebx,		%eax
	roll	$5,		%esi
	addl	%ecx,		%esi

	movl	32(%esp),	%edx
	xorl	%esi,		%eax
	addl	%edx,		%ecx
	roll	$10,		%edi
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$14,		%ecx
	addl	%ebp,		%ecx

	xorl	%edi,		%eax
	movl	28(%esp),	%edx
	xorl	%ecx,		%eax
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$10,		%esi
	addl	%edx,		%ebp
	xorl	%esi,		%eax
	roll	$6,		%ebp
	addl	%ebx,		%ebp

	movl	24(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%edx,		%ebx
	roll	$10,		%ecx
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$8,		%ebx
	addl	%edi,		%ebx

	xorl	%ecx,		%eax
	movl	8(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$10,		%ebp
	addl	%edx,		%edi
	xorl	%ebp,		%eax
	roll	$13,		%edi
	addl	%esi,		%edi

	movl	52(%esp),	%edx
	xorl	%edi,		%eax
	addl	%edx,		%esi
	roll	$10,		%ebx
	addl	%eax,		%esi
	movl	%edi,		%eax
	roll	$6,		%esi
	addl	%ecx,		%esi

	xorl	%ebx,		%eax
	movl	56(%esp),	%edx
	xorl	%esi,		%eax
	addl	%eax,		%ecx
	movl	%esi,		%eax
	roll	$10,		%edi
	addl	%edx,		%ecx
	xorl	%edi,		%eax
	roll	$5,		%ecx
	addl	%ebp,		%ecx

	movl	(%esp),		%edx
	xorl	%ecx,		%eax
	addl	%edx,		%ebp
	roll	$10,		%esi
	addl	%eax,		%ebp
	movl	%ecx,		%eax
	roll	$15,		%ebp
	addl	%ebx,		%ebp

	xorl	%esi,		%eax
	movl	12(%esp),	%edx
	xorl	%ebp,		%eax
	addl	%eax,		%ebx
	movl	%ebp,		%eax
	roll	$10,		%ecx
	addl	%edx,		%ebx
	xorl	%ecx,		%eax
	roll	$13,		%ebx
	addl	%edi,		%ebx

	movl	36(%esp),	%edx
	xorl	%ebx,		%eax
	addl	%edx,		%edi
	roll	$10,		%ebp
	addl	%eax,		%edi
	movl	%ebx,		%eax
	roll	$11,		%edi
	addl	%esi,		%edi

	xorl	%ebp,		%eax
	movl	44(%esp),	%edx
	xorl	%edi,		%eax
	addl	%eax,		%esi
	roll	$10,		%ebx
	addl	%edx,		%esi
	movl	128(%esp),	%edx
	roll	$11,		%esi
	addl	%ecx,		%esi
	movl	4(%edx),	%eax
	addl	%eax,		%ebx
	movl	72(%esp),	%eax
	addl	%eax,		%ebx
	movl	8(%edx),	%eax
	addl	%eax,		%ebp
	movl	76(%esp),	%eax
	addl	%eax,		%ebp
	movl	12(%edx),	%eax
	addl	%eax,		%ecx
	movl	80(%esp),	%eax
	addl	%eax,		%ecx
	movl	16(%edx),	%eax
	addl	%eax,		%esi
	movl	64(%esp),	%eax
	addl	%eax,		%esi
	movl	(%edx),		%eax
	addl	%eax,		%edi
	movl	68(%esp),	%eax
	addl	%eax,		%edi
	movl	136(%esp),	%eax
	movl	%ebx,		(%edx)
	movl	%ebp,		4(%edx)
	movl	%ecx,		8(%edx)
	subl	$1,		%eax
	movl	%esi,		12(%edx)
	movl	%edi,		16(%edx)
	jle	.L001get_out
	movl	%eax,		136(%esp)
	movl	%ecx,		%edi
	movl	132(%esp),	%eax
	movl	%ebx,		%ecx
	addl	$64,		%eax
	movl	%ebp,		%esi
	movl	%eax,		132(%esp)
	jmp	.L000start
.L001get_out:
	addl	$108,		%esp
	popl	%ebx
	popl	%ebp
	popl	%edi
	popl	%esi
	ret
.L_ripemd160_block_asm_host_order_end:
	.size	ripemd160_block_asm_host_order,.L_ripemd160_block_asm_host_order_end-ripemd160_block_asm_host_order
.ident	"desasm.pl"
