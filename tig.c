/* ncurses(3): Must be defined to have extended wide-character functions. */
#define _XOPEN_SOURCE_EXTENDED

static size_t utf8_length(const char *string, size_t max_width, int *trimmed, bool reserve);
	"git show --pretty=fuller --no-color --root --patch-with-stat --find-copies-harder -C %s 2>/dev/null"
	"git log --no-color --topo-order --parents --boundary --pretty=raw %s 2>/dev/null"
	unsigned int ltag:1;	/* If so, is the tag local? */
	REQ_(TOGGLE_DATE,	"Toggle date display"), \
	REQ_(TOGGLE_AUTHOR,	"Toggle author display"), \
	REQ_(TOGGLE_REFS,	"Toggle reference display (tags/branches)"), \
static bool opt_date			= TRUE;
static bool opt_author			= TRUE;
static bool opt_show_refs		= TRUE;
static signed char opt_is_inside_work_tree	= -1; /* set to TRUE or FALSE */
	char *subcommand;
	if (argc <= 1)
		return TRUE;
	subcommand = argv[1];
	if (!strcmp(subcommand, "status")) {
		opt_request = REQ_VIEW_STATUS;
		if (argc > 2)
			warn("ignoring arguments after `%s'", subcommand);
		return TRUE;
	} else if (!strcmp(subcommand, "show")) {
		opt_request = REQ_VIEW_DIFF;
	} else if (!strcmp(subcommand, "log") || !strcmp(subcommand, "diff")) {
		opt_request = subcommand[0] == 'l'
			    ? REQ_VIEW_LOG : REQ_VIEW_DIFF;
		warn("`tig %s' has been deprecated", subcommand);

	} else {
		subcommand = NULL;
	}

	for (i = 1 + !!subcommand; i < argc; i++) {
		char *opt = argv[i];
			string_copy(opt_cmd, "git log --no-color --pretty=raw --boundary --parents");
			string_format(opt_cmd, "git %s", subcommand);
LINE(MAIN_LOCAL_TAG,"",			COLOR_MAGENTA,	COLOR_DEFAULT,	A_BOLD), \
	{ 'D',		REQ_TOGGLE_DATE },
	{ 'A',		REQ_TOGGLE_AUTHOR },
	{ 'F',		REQ_TOGGLE_REFS },
static bool parse_bool(const char *s)
{
	return (!strcmp(s, "1") || !strcmp(s, "true") ||
		!strcmp(s, "yes")) ? TRUE : FALSE;
}

	if (!strcmp(argv[0], "show-author")) {
		opt_author = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-date")) {
		opt_date = parse_bool(argv[2]);
		return OK;
	}

		opt_rev_graph = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-refs")) {
		opt_show_refs = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-line-numbers")) {
		opt_line_number = parse_bool(argv[2]);
	size_t lines;		/* Total number of lines */
	size_t line_alloc;	/* Total number of allocated lines */
	size_t line_size;	/* Total number of used lines */
static int
draw_text(struct view *view, const char *string, int max_len,
	  bool use_tilde, int tilde_attr)
{
	int len = 0;
	int trimmed = FALSE;

	if (max_len <= 0)
		return 0;

	if (opt_utf8) {
		len = utf8_length(string, max_len, &trimmed, use_tilde);
	} else {
		len = strlen(string);
		if (len > max_len) {
			if (use_tilde) {
				max_len -= 1;
			}
			len = max_len;
			trimmed = TRUE;
		}
	}

	waddnstr(view->win, string, len);
	if (trimmed && use_tilde) {
		if (tilde_attr != -1)
			wattrset(view->win, tilde_attr);
		waddch(view->win, '~');
		len++;
	}

	return len;
}

#define ITEM_CHUNK_SIZE 256
static void *
realloc_items(void *mem, size_t *size, size_t new_size, size_t item_size)
{
	size_t num_chunks = *size / ITEM_CHUNK_SIZE;
	size_t num_chunks_new = (new_size + ITEM_CHUNK_SIZE - 1) / ITEM_CHUNK_SIZE;

	if (mem == NULL || num_chunks != num_chunks_new) {
		*size = num_chunks_new * ITEM_CHUNK_SIZE;
		mem = realloc(mem, *size * item_size);
	}

	return mem;
}

	size_t alloc = view->line_alloc;
	struct line *tmp = realloc_items(view->line, &alloc, line_size,
					 sizeof(*view->line));
	view->line_alloc = alloc;
	if (view->ops->read(view, NULL))
		end_update(view);
	case REQ_TOGGLE_DATE:
		opt_date = !opt_date;
		redraw_display();
		break;

	case REQ_TOGGLE_AUTHOR:
		opt_author = !opt_author;
		redraw_display();
		break;

	case REQ_TOGGLE_REFS:
		opt_show_refs = !opt_show_refs;
		redraw_display();
		break;

		int tilde_attr = get_line_attr(LINE_MAIN_DELIM);
		draw_text(view, text, view->width, TRUE, tilde_attr);
	char *commit_id = (char *)line->data + STRING_SIZE("commit ");
		char *text = (char *)line->data + STRING_SIZE("commit ");
	if (!text)
		return TRUE;
	char *text = (char *)line->data + STRING_SIZE("100644 blob ");
		char name[SIZEOF_STR];
		char name[SIZEOF_STR];
	if (bufsize < 99 ||
	file->old.name[0] = file->new.name[0] = 0;
					int collapse = !strcmp(buf, unmerged->new.name);
			/* Grab the old name for rename/copy. */
			if (!*file->old.name &&
			    (file->status == 'R' || file->status == 'C')) {
				sepsize = sep - buf + 1;
				string_ncopy(file->old.name, buf, sepsize);
				bufsize -= sepsize;
				memmove(buf, sep + 1, bufsize);

				sep = memchr(buf, 0, bufsize);
				if (!sep)
					break;
				sepsize = sep - buf + 1;
			}

			string_ncopy(file->new.name, buf, sepsize);
			if (!*file->old.name)
				string_copy(file->old.name, file->new.name);
#define STATUS_DIFF_INDEX_CMD "git diff-index -z --diff-filter=ACDMRTXB --cached -M HEAD"
	"git diff-index --root --patch-with-stat -C -M --cached HEAD -- %s %s 2>/dev/null"
	"git diff-files --root --patch-with-stat -C -M -- %s %s 2>/dev/null"
	view->lines = view->line_alloc = view->line_size = view->lineno = 0;
	system("git update-index -q --refresh");

	int tilde_attr = get_line_attr(LINE_MAIN_DELIM);
		tilde_attr = -1;
		draw_text(view, text, view->width, TRUE, tilde_attr);
	if (view->width < 5)
		return TRUE;
	draw_text(view, status->new.name, view->width - 5, TRUE, tilde_attr);
	char oldpath[SIZEOF_STR] = "";
	char newpath[SIZEOF_STR] = "";
	if (status) {
		if (sq_quote(oldpath, 0, status->old.name) >= sizeof(oldpath))
			return REQ_QUIT;
		/* Diffs for unmerged entries are empty when pasing the
		 * new path, so leave it empty. */
		if (status->status != 'U' &&
		    sq_quote(newpath, 0, status->new.name) >= sizeof(newpath))
			return REQ_QUIT;
	}
					STATUS_DIFF_INDEX_SHOW_CMD, oldpath, newpath))
					STATUS_DIFF_FILES_SHOW_CMD, oldpath, newpath))
		opt_pipe = fopen(status->new.name, "r");
		string_format(VIEW(REQ_VIEW_STAGE)->ref, info, stage_status.new.name);
					status->old.name, 0))
		if (!string_format_from(buf, &bufsize, "%s%c", status->new.name, 0))
		open_mergetool(status->new.name);
		open_editor(status->status != '?', status->new.name);
	if (status && !string_format(file, "'%s'", status->new.name))
		case S_NAME:	text = status->new.name;	break;
		if (!stage_status.new.name[0])
		open_editor(stage_status.status != '?', stage_status.new.name);
	bool has_parents;		/* Rewritten --parents seen. */
	int tilde_attr;
	int space;
	space = view->width;
		tilde_attr = -1;
		tilde_attr = get_line_attr(LINE_MAIN_DELIM);
	if (opt_date) {
		int n;
		timelen = strftime(buf, sizeof(buf), DATE_FORMAT, &commit->time);
		n = draw_text(view, buf, view->width - col, FALSE, tilde_attr);
		draw_text(view, " ", view->width - col - n, FALSE, tilde_attr);

		col += DATE_COLS;
		wmove(view->win, lineno, col);
		if (col >= view->width)
			return TRUE;
	}
	if (opt_author) {
		int max_len;
		max_len = view->width - col;
		if (max_len > AUTHOR_COLS - 1)
			max_len = AUTHOR_COLS - 1;
		draw_text(view, commit->author, max_len, TRUE, tilde_attr);
		col += AUTHOR_COLS;
		if (col >= view->width)
			return TRUE;
		size_t graph_size = view->width - col;
		if (graph_size > commit->graph_size)
			graph_size = commit->graph_size;
		for (i = 0; i < graph_size; i++)
		if (col >= view->width)
			return TRUE;
		waddch(view->win, ' ');
	if (opt_show_refs && commit->refs) {
			else if (commit->refs[i]->ltag)
				wattrset(view->win, get_line_attr(LINE_MAIN_LOCAL_TAG));

			col += draw_text(view, "[", view->width - col, TRUE, tilde_attr);
			col += draw_text(view, commit->refs[i]->name, view->width - col,
					 TRUE, tilde_attr);
			col += draw_text(view, "]", view->width - col, TRUE, tilde_attr);
			col += draw_text(view, " ", view->width - col, TRUE, tilde_attr);
			if (col >= view->width)
				return TRUE;
	draw_text(view, commit->title, view->width - col, TRUE, tilde_attr);

		while ((line = strchr(line, ' '))) {
			line++;
			push_rev_graph(graph->parents, line);
			commit->has_parents = TRUE;
		}
		if (commit->has_parents)
			break;
	if (c == '\t')
		return opt_tab_size;

 * shown. If the reserve flag is TRUE, it will reserve at least one
 * trailing character, which can be useful when drawing a delimiter.
utf8_length(const char *string, size_t max_width, int *trimmed, bool reserve)
	unsigned char last_bytes = 0;
			if (reserve && width - ucwidth == max_width) {
				string -= last_bytes;
			}
		last_bytes = bytes;
static struct ref *refs = NULL;
static size_t refs_alloc = 0;
static size_t refs_size = 0;
static struct ref ***id_refs = NULL;
static size_t id_refs_alloc = 0;
static size_t id_refs_size = 0;
	size_t ref_list_alloc = 0;
	tmp_id_refs = realloc_items(id_refs, &id_refs_alloc, id_refs_size + 1,
				    sizeof(*id_refs));
		tmp = realloc_items(ref_list, &ref_list_alloc,
				    ref_list_size + 1, sizeof(*ref_list));
	bool ltag = FALSE;
	bool check_replace = FALSE;
		if (!strcmp(name + namelen - 3, "^{}")) {
			namelen -= 3;
			name[namelen] = 0;
			if (refs_size > 0 && refs[refs_size - 1].ltag == TRUE)
				check_replace = TRUE;
		} else {
			ltag = TRUE;
		}
	if (check_replace && !strcmp(name, refs[refs_size - 1].name)) {
		/* it's an annotated tag, replace the previous sha1 with the
		 * resolved commit id; relies on the fact git-ls-remote lists
		 * the commit id of an annotated tag right beofre the commit id
		 * it points to. */
		refs[refs_size - 1].ltag = ltag;
		string_copy_rev(refs[refs_size - 1].id, id);

		return OK;
	}
	refs = realloc_items(refs, &refs_alloc, refs_size + 1, sizeof(*refs));
	ref->ltag = ltag;
	if (*opt_encoding && strcasecmp(opt_encoding, "UTF-8"))
		opt_utf8 = FALSE;
