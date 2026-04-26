void write_report (your variables) {
    std::ofstream outfile (ofilename);
    if (!outfile)
        std::cerr<<"File failed to open\n";
}
