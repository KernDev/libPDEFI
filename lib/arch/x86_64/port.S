global inb
inb:
	push rdx

	mov dx, cx
	in al, dx
.done:
	pop rdx

	ret

global outb
outb:
	push rax

	mov al, dl
	mov dx, cx
	out dx, al
.done:
	pop rax

	ret
