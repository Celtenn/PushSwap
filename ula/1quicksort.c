./push_swap 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 101 103 105 107 109 111 113 115 117 119 121 123 125 127 129 131 133 135 137 139 141 143 145 147 149 151 153 155 157 159 161 163 165 167 169 171 173 175 177 179 181 183 185 187 189 191 193 195 197 199 201 203 205 207 209 211 213 215 217 219 221 223 225 227 229 231 233 235 237 239 241 243 245 247 249 251 253 255 257 259 261 263 265 267 269 271 273 275 277 279 281 283 285 287 289 291 293 295 297 299 301 303 305 307 309 311 313 315 317 319 321 323 325 327 329 331 333 335 337 339 341 343 345 347 349 351 353 355 357 359 361 363 365 367 369 371 373 375 377 379 381 383 385 387 389 391 393 395 397 399 401 403 405 407 409 411 413 415 417 419 421 423 425 427 429 431 433 435 437 439 441 443 445 447 449 451 453 455 457 459 461 463 465 467 469 471 473 475 477 479 481 483 485 487 489 491 493 495 497 499 500 498 496 494 492 490 488 486 484 482 480 478 476 474 472 470 468 466 464 462 460 458 456 454 452 450 448 446 444 442 440 438 436 434 432 430 428 426 424 422 420 418 416 414 412 410 408 406 404 402 400 398 396 394 392 390 388 386 384 382 380 378 376 374 372 370 368 366 364 362 360 358 356 354 352 350 348 346 344 342 340 338 336 334 332 330 328 326 324 322 320 318 316 314 312 310 308 306 304 302 300 298 296 294 292 290 288 286 284 282 280 278 276 274 272 270 268 266 264 262 260 258 256 254 252 250 248 246 244 242 240 238 236 234 232 230 228 226 224 222 220 218 216 214 212 210 208 206 204 202 200 198 196 194 192 190 188 186 184 182 180 178 176 174 172 170 168 166 164 162 160 158 156 154 152 150 148 146 144 142 140 138 136 134 132 130 128 126 124 122 120 118 116 114 112 110 108 106 104 102 100 98 96 94 92 90 88 86 84 82 80 78 76 74 72 70 68 66 64 62 60 58 56 54 52 50 48 46 44 42 40 38 36 34 32 30 28 26 24 22 20 18 16 14 12 10 8 6 4 2
#include "push_swap.h"

int	pivot_of_numbers(int *pivot, t_node *head, int size)
{
	t_node	*temporaire_stack;
	t_node	*current;
	int		i;

	i = 0;
	temporaire_stack = NULL;
	if (head == NULL)
		return (0);
	current = head;
	while (current != NULL && i < size)
	{
		add_node(&temporaire_stack, current->value);
		current = current->next;
		i++;
	}
	temporary_sort(temporaire_stack);
	i = 0;
	current = temporaire_stack;
	while (i++ < size / 2)
		current = current->next;
	*pivot = current->value;
	free_list(temporaire_stack);
	return (1);
}

int	quicksort_stack_a(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers = 0;

	if (check_sorted(stack->a, 0) == 1)
		return (1);
	if (len <= 3)
	{
		quicksort_three_stack_a(stack, len);
		return (1);
	}
	if ((check_sorted_lo(stack->a, 1, len) == 1))
	{
		while (len > numbers)
		{
			push_b(stack);
			numbers++;
		}
		while (numbers > 0)
		{
			rotate_b(stack);
			numbers--;
		}
		while (numbers < len)
		{
			reverse_rotate_b(stack);
			push_a(stack);
			numbers++;
		}
	}
	numbers = len;
	if (!pivot_of_numbers(&pivot, stack->a, len))
		return (0);
	while (len != (numbers / 2 + numbers % 2))
	{
		if (stack->a->value < pivot && len--)
			push_b(stack);
		else if (++count_r)
			rotate_a(stack);
	}
	while (numbers / 2 + numbers % 2 != stack->size_a && count_r--)
		reverse_rotate_a(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}

int	quicksort_stack_b(t_stack *stack, int len, int count_r)
{
	int	pivot;
	int	numbers = 0;

	if (check_sorted(stack->b, 1) == 1)
		while (len--)
			push_a(stack);
	if (check_sorted(stack->b, 0) == 1)
	{
		while (numbers < (stack->size_b))
		{
			reverse_rotate_b(stack);
			push_a(stack);
		}
	}
	if (!stack->b)
		return (0);
	if (len <= 3)
	{
		sort_three_b(stack, len);
		return (1);
	}
	numbers = len;
	if (!pivot_of_numbers(&pivot, stack->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->b->value >= pivot && len--)
			push_a(stack);
		else if (++count_r)
			rotate_b(stack);
	}
	while (numbers / 2 != stack->size_b && count_r--)
		reverse_rotate_b(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}
