# strnstr - Linux Kernel API

> Source: https://archive.kernel.org/oldlinux/htmldocs/kernel-api/API-strnstr.html
> Collected: 2026-08-14
> Published: Unknown

strnstr — Find the first substring in a length-limited string

## NAME
strnstr — Find the first substring in a length-limited string

## SYNOPSIS
char * strnstr(const char * s1, const char * s2, size_t len);

## ARGUMENTS
const char * s1 — The string to be searched
const char * s2 — The string to search for
size_t len — the maximum number of characters to search

## DESCRIPTION
strnstr() finds the first occurrence of the substring s2 in the string s1, but not more than len characters are searched. This function is a GNU extension and is not part of the standard C library. It is available in the Linux kernel API.