TABLE snpArrayAffy50XbaI 
"Affy 100K SNP array (XbaI)"
    (
    uint bin;         "For browser speedup"
    string chrom;     "Reference sequence chromosome or scaffold"
    uint chromStart;  "Start position in chrom"
    uint chromEnd;    "End position in chrom"
    string name;      "Identifier"
    uint score;       "Not used"
    char[1] strand;   "Strand: +, - or ?"
    lstring observed; "Observed alleles"
    string rsId;      "dbSNP identifier"
    )
